class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();

        for(int i=0; i<m; ++i)
        {
            int lo = 0, hi = matrix[0].size() - 1;
            while(lo <= hi)
            {
                int mid = lo + (hi - lo)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] < target) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        return false;
    }
};
