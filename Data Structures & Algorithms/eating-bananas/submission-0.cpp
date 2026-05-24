class Solution {
public:
    bool totaltime(vector<int>& piles, int mid, int giventime)
    {
        int n = piles.size();
        long long timetaken = 0;
        for(int i=0; i<n; ++i){
            timetaken += (piles[i] + mid - 1)/ mid;
            if(timetaken > giventime) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxboundhr = INT_MIN;
        for(int i=0; i<n; ++i){
            maxboundhr = max(maxboundhr, piles[i]);
        }

        int ans = -1;
        int lo = 1, hi = maxboundhr;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(totaltime(piles, mid, h)){ 
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};
