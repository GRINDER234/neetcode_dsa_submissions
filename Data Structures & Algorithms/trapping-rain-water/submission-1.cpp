class Solution {
public:
    int trap(vector<int>& height) {
        // TC:O(N), SC:O(N)
        // int n = height.size();
        // vector<int>lmax(n);
        // vector<int>rmax(n);
        // lmax[0] = height[0];
        // rmax[n-1] = height[n-1];

        // for(int i=1; i<n; ++i)  lmax[i] = max(lmax[i-1], height[i]);
        // for(int j=n-2; j>=0; --j)  rmax[j] = max(rmax[j+1], height[j]);

        // int ans = 0;
        // for(int i=0; i<n; ++i){
        //     ans += min(lmax[i], rmax[i]) - height[i];
        // }

        //Now TC:O(N), SC:O(1)
        int n = height.size();
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        
        while(l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }else{
                ans += rmax - height[r];
                r--;
            }
        }

        return ans;
    }
};
