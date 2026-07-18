class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mpp(26, 0);
        for(int i=0; i<tasks.size(); i++){
            mpp[tasks[i] - 'A']++;
        }

        priority_queue<int>maxheap;
        for(int i=0; i<26; i++){
            if(mpp[i] > 0){
                maxheap.push(mpp[i]);
            }
        }

        int time = 0;
        while(!maxheap.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!maxheap.empty()){
                    int freq = maxheap.top();
                    maxheap.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int f : temp){
                if(f > 0){
                    maxheap.push(f);
                }
            }

            if(maxheap.empty()){
                time+=temp.size();
            }else{
                time+=n+1;
            }
        }

        return time;
    }
};
