class Solution {
public:
    void solve(int col, vector<vector<string>> &ans, vector<string> & board,
               vector<int> &LeftRow, vector<int> &UpperDiagonal,
               vector<int> &LowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (LeftRow[row] == 0 && UpperDiagonal[n - 1 + col - row] == 0 &&
                LowerDiagonal[col + row] == 0) {
                board[row][col] = 'Q';
                LeftRow[row] = 1;
                UpperDiagonal[n - 1 + col - row] = 1;
                LowerDiagonal[col + row] = 1;
                solve(col + 1, ans, board, LeftRow, UpperDiagonal, LowerDiagonal,
                      n);
                board[row][col] = '.';
                LeftRow[row] = 0;
                UpperDiagonal[n - 1 + col - row] = 0;
                LowerDiagonal[col + row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> LeftRow(n, 0), UpperDiagonal(2 * n - 1, 0),
            LowerDiagonal(2 * n - 1, 0);

        solve(0, ans, board, LeftRow, UpperDiagonal, LowerDiagonal, n);

        return ans;
    }
};