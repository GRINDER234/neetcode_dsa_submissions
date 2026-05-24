class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // THIS IS LIKE O(mlogn) approach 
        // int m = matrix.size();

        // for(int i=0; i<m; ++i)
        // {
        //     int lo = 0, hi = matrix[0].size() - 1;
        //     while(lo <= hi)
        //     {
        //         int mid = lo + (hi - lo)/2;
        //         if(matrix[i][mid] == target) return true;
        //         else if(matrix[i][mid] < target) lo = mid + 1;
        //         else hi = mid - 1;
        //     }
        // }


        int lo = 0, hi = matrix.size() * matrix[0].size() - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int r = mid / matrix[0].size(), c = mid % matrix[0].size();

            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        return false;
    }
};
