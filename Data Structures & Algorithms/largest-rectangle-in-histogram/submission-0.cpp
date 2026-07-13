class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>psbar_ht_indx(n,-1);
        vector<int>nsbar_ht_indx(n,n);
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) psbar_ht_indx[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; --i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) nsbar_ht_indx[i] = st.top();
            st.push(i);
        }

        int maxArea = INT_MIN;
        for(int i=0; i<n; i++){
            psbar_ht_indx[i] += 1;
            nsbar_ht_indx[i] -= 1;
            maxArea = max(maxArea, (heights[i] * (nsbar_ht_indx[i] - psbar_ht_indx[i] + 1)));
        }

        return maxArea;
    }
};
