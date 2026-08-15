class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int r, int c, int k) {
        int n = board.size();
        int m = board[0].size();
        if (k == word.size()) {
            return true;
        }

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == word[k]) {
                char temp = word[k];
                board[nr][nc] = '$';
                k++;
                if (solve(board, word, nr, nc, k)) {
                    return true;
                }
                k--;
                board[nr][nc] = temp;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    char temp = word[0];
                    board[i][j] = '$';
                    if (solve(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = temp;
                }
            }
        }

        return false;
    }
};