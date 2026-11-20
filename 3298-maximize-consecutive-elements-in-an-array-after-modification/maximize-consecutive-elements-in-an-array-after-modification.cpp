
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        dp.reserve(nums.size() * 2);

        int ans = 0;

        for (int x : nums) {
            // Increment current element: x -> x + 1
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);

            // Keep current element unchanged
            dp[x] = max(dp[x], dp[x - 1] + 1);

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};
