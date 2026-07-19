class Solution {
private:
    bool isValid(int row, int col, int n, int m){
        if(row >= 0 && row < n && col >= 0 && col < m) return true;
        return false;
    }

    int countIslands(vector<vector<char>>&grid, vector<vector<bool>>&vis, int drow[], int dcol[], int i, int j, int n, int m){
        vis[i][j] = true;

        for(int k=0; k<4; k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if(isValid(nrow, ncol, n, m)){
                if(!vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    countIslands(grid, vis, drow, dcol, nrow, ncol, n, m);
                }
            }
        }

        return 1;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count += countIslands(grid,vis,drow,dcol,i,j,n,m);
                }
            }
        }

        return count;
    }
};
