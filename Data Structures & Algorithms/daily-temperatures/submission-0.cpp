class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<int>psei;
        for(int i=n-1; i>=0; --i){
            while(!psei.empty() && temperatures[psei.top()] <= temperatures[i]){
                psei.pop();
            }

            if(psei.empty()) ans[i] = 0;
            else ans[i] = abs(i - psei.top());

            psei.push(i);
        }

        return ans;
    }
};
