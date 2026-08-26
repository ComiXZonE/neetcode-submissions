class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int i = (left + right) / 2;

            int x = i / n;
            int y = i % n;

            if (target == matrix[x][y]) {
                return true;
            }

            if (target < matrix[x][y]) {
                right = i - 1;
            }
            else
            {
                left = i + 1;
            }
        }

        return false;
    }
};
