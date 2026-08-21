class Solution {
public:
    bool isValid(string s) {
        static unordered_map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        stack<char> st;

        for (char c : s) {
            if (st.empty() || c != pairs[st.top()]) {
                st.push(c);
            }
            else {
                st.pop();
            }
        }

        return st.empty();
    }
};
