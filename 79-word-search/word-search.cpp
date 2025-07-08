class Solution {
public:
    bool SearchNext(vector<vector<char>> & board, string word, int row, int col,
                    int idx, int m, int n) {
        if (idx == word.size()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= m || col >= n)
            return false;
        if (board[row][col] != word[idx] || board[row][col] == '!')
            return false;

        char temp = board[row][col];
        board[row][col] = '!';
        bool top = SearchNext(board, word, row - 1, col, idx + 1, m, n);
        bool right = SearchNext(board, word, row, col + 1, idx + 1, m, n);
        bool bottom = SearchNext(board, word, row + 1, col, idx + 1, m, n);
        bool left = SearchNext(board, word, row, col - 1, idx + 1, m, n);
        board[row][col] = temp;
        return top || right || bottom || left;
    }

    bool IsExist(vector<vector<char>> board, string word) {
        int m = board.size();
        int n = board[0].size();
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[idx]) {
                    if (SearchNext(board, word, i, j, idx, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = IsExist(board, word);
        if (res)
            return true;
        else
            return false;
    }
};