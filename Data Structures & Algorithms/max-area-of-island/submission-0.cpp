class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<bool>>&vis, int drow[], int dcol[], int n, int m){
        vis[i][j] = true;
        int area = 1;
        for(int k=0; k<4; k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    area = area + dfs(nrow, ncol, grid, vis, drow, dcol, n, m);
                }
            }
        }

        return area;

    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        int maxarea = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1) maxarea = max(maxarea, dfs(i,j,grid,vis,drow,dcol,n,m));
            }
        }

        return maxarea;
    }
};
