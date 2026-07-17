class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>maxheap;

        for(int i=0; i<n; i++){
            maxheap.push(stones[i]);
        }

        while(maxheap.size() > 1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();

            if(x > y){
                maxheap.push(x-y);
            }
        }
        maxheap.push(0);
        return maxheap.top();
    }
};
