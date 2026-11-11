
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long n1 = need1;
        long long n2 = need2;

        // Option 1: Buy only individual items
        long long ans = n1 * cost1 + n2 * cost2;

        // Option 2: Buy type 3 items for the common requirement
        long long common = min(n1, n2);

        long long cost = common * costBoth
                       + (n1 - common) * cost1
                       + (n2 - common) * cost2;

        ans = min(ans, cost);

        // Option 3: Buy type 3 items for both requirements
        // even if one requirement gets exceeded
        cost = max(n1, n2) * costBoth;

        ans = min(ans, cost);

        return ans;
    }
};
