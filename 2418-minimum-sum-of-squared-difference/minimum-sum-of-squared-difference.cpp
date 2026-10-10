class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<long long> diff(n);
        long long total = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (k >= total) return 0;

        long long lo = 0, hi = mx;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long need = 0;

            for (long long d : diff) {
                if (d > mid) need += d - mid;
                if (need > k) break;
            }

            if (need <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long ans = 0, used = 0;

        for (long long d : diff) {
            if (d > lo) {
                used += d - lo;
                ans += lo * lo;
            } else {
                ans += d * d;
            }
        }

        long long remaining = k - used;

        // Reduce remaining differences from lo to lo-1.
        for (long long d : diff) {
            if (remaining == 0) break;
            if (d >= lo) {
                ans += (lo - 1) * (lo - 1) - lo * lo;
                remaining--;
            }
        }

        return ans;
    }
};