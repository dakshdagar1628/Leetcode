class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        // Count factors and find minimum price
        for (auto &x : items) {
            freq[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }

        // Count how many items each factor can unlock
        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long rem = budget;

        // Buy items that give 2 copies per purchase
        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            if (2LL * minPrice <= price)
                break;

            int cnt = gain[factor];

            long long take = min((long long)cnt, rem / price);

            ans += 2 * take;
            rem -= take * price;
        }

        // Spend remaining budget on cheapest items
        ans += rem / minPrice;

        return (int)ans;
    }
};
