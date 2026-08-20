class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (const string& str : strs) {
            result.append(to_string(str.length()));
            result.push_back('#');
            result.append(str);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        while (!s.empty()) {
            int hash_pos = s.find("#");
            int length = stoi(s.substr(0, hash_pos));
            result.push_back(s.substr(hash_pos + 1, length));
            s.erase(0, hash_pos + length + 1);
        }

        return result;
    }
};
