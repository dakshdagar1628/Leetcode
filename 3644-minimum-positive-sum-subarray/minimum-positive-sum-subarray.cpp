
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        multiset<long long> st;
        long long ans = LLONG_MAX;

        for (int j = 0; j <= n; j++) {

            // Add valid starting prefix index
            if (j - l >= 0) {
                st.insert(pref[j - l]);
            }

            // Remove indices outside the window
            if (j - r - 1 >= 0) {
                auto it = st.find(pref[j - r - 1]);
                st.erase(it);
            }

            // Find the largest prefix sum smaller than pref[j]
            auto it = st.lower_bound(pref[j]);

            if (it != st.begin()) {
                --it;

                long long sum = pref[j] - *it;
                ans = min(ans, sum);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};
