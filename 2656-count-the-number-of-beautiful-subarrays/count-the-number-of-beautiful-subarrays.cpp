class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long xr = 0;
        long long cnt = 0;
        map<long long,long long> mpp;
        mpp[xr]++;
        for(int i = 0; i < nums.size(); i++)
        {
            xr ^= nums[i];
            long long x = xr ^ 0;
            cnt += mpp[x]; 
            mpp[xr]++;
        }
        return cnt;
    }
};