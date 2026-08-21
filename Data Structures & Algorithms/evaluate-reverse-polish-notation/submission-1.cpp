class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        const string operators = "+-*/";
        stack<int> eval;

        for (const string& t : tokens) {
            if (operators.contains(t)) {
                int op2 = eval.top();
                eval.pop();
                int op1 = eval.top();
                eval.pop();
                switch (t.front()) {
                    case '+': eval.push(op1 + op2); break;
                    case '-': eval.push(op1 - op2); break;
                    case '*': eval.push(op1 * op2); break;
                    case '/': eval.push(op1 / op2); break;
                }
            }
            else {
                int op = stoi(t);
                eval.push(op);
            }
        }

        return eval.top();
    }
};
