class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        const int SIZE = 1 << 20;

        vector<long long> freq(SIZE, 0);

        long long xr = 0;
        long long cnt = 0;

        freq[0] = 1;

        for (int num : nums) {
            xr ^= num;

            cnt += freq[xr];

            freq[xr]++;
        }

        return cnt;
    }
};