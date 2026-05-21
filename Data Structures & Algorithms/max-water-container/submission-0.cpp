class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int mxarea = INT_MIN;
        while(i < j)
        {
            if(heights[i] < heights[j]){
                int area = (j - i) * heights[i];
                mxarea = max(area, mxarea);
                i++;
            }else{
                int area = (j - i) * heights[j];
                mxarea = max(area, mxarea);
                j--;
            }
        }

        return mxarea;
    }
};
