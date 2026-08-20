constexpr int SUDOKU_SIZE = 9;
constexpr std::array<std::pair<int, int>, SUDOKU_SIZE> subbox_centers = {
    {{1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7}}};

constexpr std::array<std::pair<int, int>, SUDOKU_SIZE> neighbor_offsets = {
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < SUDOKU_SIZE; i++) {
            if (!isValidRow(board, i) || !isValidColumn(board, i) || !isValidSubBox(board, i)) {
                return false;
            }
        }

        return true;
    }

    bool isValidRow(vector<vector<char>>& board, int idx) {
        unordered_set<char> elem_set;

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            char c = board[idx][i];
            if (c != '.' && elem_set.contains(c)) {
                return false;
            }
            elem_set.insert(c);
        }

        return true;
    }

    bool isValidColumn(vector<vector<char>>& board, int idx) {
        unordered_set<char> elem_set;

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            char c = board[i][idx];
            if (c != '.' && elem_set.contains(c)) {
                return false;
            }
            elem_set.insert(c);
        }

        return true;
    }

    bool isValidSubBox(vector<vector<char>>& board, int idx) {
        unordered_set<char> elem_set;

        for (int i = 0; i < SUDOKU_SIZE; i++) {
            char c = board[subbox_centers[idx].first + neighbor_offsets[i].first]
                          [subbox_centers[idx].second + neighbor_offsets[i].second];
            if (c != '.' && elem_set.contains(c)) {
                return false;
            }
            elem_set.insert(c);
        }

        return true;
    }
};
