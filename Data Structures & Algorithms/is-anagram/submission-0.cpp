class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> appearance_map;

        for (char& c : s) {
            if (appearance_map.contains(c))
                appearance_map[c]++;
            else
                appearance_map[c] = 1;
        }

        for (char& c : t) {
            if (!appearance_map.contains(c))
                return false;
            else if (--appearance_map[c] == 0)
                appearance_map.erase(c);
        }

        if (appearance_map.empty())
            return true;

        return false;
    }
};
