class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long xr = 0;
        long long cnt = 0;

        unordered_map<long long, long long> mpp;
        mpp[0] = 1;

        for (int num : nums) {
            xr ^= num;

            cnt += mpp[xr];

            mpp[xr]++;
        }

        return cnt;
    }
};