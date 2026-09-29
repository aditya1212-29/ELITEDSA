class Solution {
public:
    bool check(int r, int c, vector<vector<char>> &board){
        int x = board.size(), y = board[0].size();
        if(r < 0 || r >= x || c < 0 || c >= y) return 0;
        return 1;
    }
    void solve(int i, int j, vector<vector<char>> &board, string &word, bool &flag, vector<vector<int>> &visited, int cnt){
        if(cnt == word.size()){
            flag = 1;
            return;
        }
        vector<int>a = {0, 0, 1, -1};
        vector<int>b = {-1, 1, 0, 0};
            for(int k = 0; k < 4; k++){
                int nr = i + a[k];
                int nc = j + b[k];
                if(check(nr, nc, board) && word[cnt] == board[nr][nc] && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    solve(nr, nc, board, word, flag, visited, cnt + 1);
                    visited[nr][nc] = 0;
                }
        }
        return ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = 0;
        int n = board.size(), m = board[0].size();
        int cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m , 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!flag){
                    if(board[i][j] == word[0]){
                        visited[i][j] = 1;
                        solve(i, j, board, word, flag, visited, cnt + 1);
                        visited[i][j] = 0;
                    }
                }
                else break;
            }
        }
        return flag;
    }
};