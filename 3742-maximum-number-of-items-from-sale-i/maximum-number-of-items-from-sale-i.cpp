
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mn = 1501;

        vector<int> freq(1501, 0);
        vector<int> cnt(1501, 0);
        vector<int> dp(budget + 1, 0);

        for (auto &x : items) {
            freq[x[0]]++;
            mn = min(mn, x[1]);
        }

        // Count all factors divisible by each factor
        for (int i = 1; i <= 1500; i++) {
            for (int j = i; j <= 1500; j += i) {
                cnt[i] += freq[j];
            }
        }

        // 0/1 Knapsack
        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + cnt[factor]);
            }
        }

        int ans = 0;

        // Buy cheapest items with remaining budget
        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / mn);
        }

        return ans;
    }
};
