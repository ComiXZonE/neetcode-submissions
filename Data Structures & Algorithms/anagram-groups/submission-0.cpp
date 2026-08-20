class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> results;

        for (const string& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            results[tmp].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(results.size());

        for (auto& [key, vec] : results) {
            result.push_back(std::move(vec));
        }   

        return result;
    }
};
