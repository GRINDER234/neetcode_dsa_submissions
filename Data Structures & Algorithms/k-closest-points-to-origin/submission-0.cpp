class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>maxheap;

        int i=0;
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            maxheap.push({dist, i});
            i=i+1;
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }

        vector<vector<int>>result;
        while(!maxheap.empty()){
            result.push_back({points[maxheap.top().second][0], points[maxheap.top().second][1]});
            maxheap.pop();
        }

        return result;

    }
};
