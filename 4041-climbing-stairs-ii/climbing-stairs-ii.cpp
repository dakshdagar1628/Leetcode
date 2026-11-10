
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = LLONG_MAX / 4;

        long long a = 0, b = INF, c = INF;

        for (int i = 1; i <= n; i++) {
            long long cur = costs[i - 1] + min({
                a + 1,
                b + 4,
                c + 9
            });

            c = b;
            b = a;
            a = cur;
        }

        return (int)a;
    }
};
