class Solution {
private:
    bool backtrack_dfs(vector<vector<char>>&board,string word,int i,int j,int k,int drow[], int dcol[], vector<vector<bool>>&vis, int n,int m){
        if(k == word.size()){
            return true;
        }

        vis[i][j] = true;

        for(int l = 0; l<4; l++){
            int nrow = i + drow[l];
            int ncol = j + dcol[l];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[k]){
                if(backtrack_dfs(board, word, nrow, ncol, k+1, drow, dcol, vis, n, m)) return true;
            }
        }

        vis[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(word.size() == 1) return true;
                    vector<vector<bool>>vis(n, vector<bool>(m, false));
                    if(backtrack_dfs(board, word, i, j, 1, drow, dcol, vis, n, m)) return true;
                }
            }
        }

        return false;
    }
};
