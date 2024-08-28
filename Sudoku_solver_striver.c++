class Solution {
public:
    bool possible(char num, vector<vector<char>>& board, int row, int col) {
        // Check the current row
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        // Check the current column
        for (int i = 0; i < board[0].size(); i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        // Check the 3x3 subgrid
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;
        for (int i = startrow; i < startrow + 3; i++) {
            for (int j = startcol; j < startcol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (possible(c, board, i, j)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};