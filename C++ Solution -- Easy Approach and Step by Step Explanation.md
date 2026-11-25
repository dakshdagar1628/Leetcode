## 01. C++ Solution || Easy Approach and Step by Step Explanation

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/geek-and-her-destination--145724/1)

### Problem Description

**Task:** Geek starts at position 0 on the positive X-axis and needs to reach or pass position d on the positive X-axis. Geek normally follows a repeating movement pattern:Move forward by a units, taking a seconds.Move backward by b units, taking b seconds.Geek also has a special jump that moves him exactly j units forward in 1 second. He can use it at any time, even in the middle of a forward or backward movement, and the journey ends immediately after the jump.Given five integers a, b, d, l, and r. For every integer j in the range [l, r], find the minimum time required for Geek to reach or pass position d. He may either use the special jump or reach the destination using normal movement alone, whichever takes less time.Return the sum of the minimum times for all jump lengths from l to r. Since, the answer can be large, return modulo 10⁹ + 7. Note: Each jump length is considered independently.Examples:Input: a = 2, b = 1, d = 5, l = 3, r = 4Output: 5Explanation: For j = 3, Geek moves 2 units forward, then takes a jump of 3 units to reach the destination. The minimum time required is 3 seconds.For j = 4, Geek moves 1 unit forward, then takes a jump of 4 units to reach the destination. The minimum time required is 2 seconds.Total sum for the range [l, r] = 3 + 2 = 5.Input: a = 4, b = 2, d = 8, l = 2, r = 4Output: 26Explanation:For j = 2, Geek moves 4 units forward, then 2 units backward. She then moves 4 units forward again and takes a jump of 2 units to reach the destination. The minimum time required is 11 seconds.For j = 3, Geek moves 4 units forward, then 2 units backward. She then moves 3 units forward and takes a jump of 3 units to reach the destination. The minimum time required is 10 seconds.For j = 4, Geek moves 4 units forward, then takes a jump of 4 units to reach the destination. The minimum time required is 5 seconds.Total sum for the range [l, r] = 11 + 10 + 5 = 26.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-25 22:22:40
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
    using ll = long long;
    using i128 = __int128_t;

    const ll MOD = 1000000007;

    // Sum of floor((a*i+b)/m), for i = 0 to n-1
    i128 floorSum(i128 n, i128 m, i128 a, i128 b) {
        i128 ans = 0;

        while (true) {
            if (a >= m) {
                ans += (n - 1) * n * (a / m) / 2;
                a %= m;
            }

            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }

            i128 y = a * n + b;

            if (y < m) break;

            n = y / m;
            b = y % m;
            swap(m, a);
        }

        return ans;
    }

    // Normal movement time to reach x
    i128 getTime(ll x, ll a, ll b) {
        if (x <= 0) return 0;
        if (x <= a) return x;

        ll D = a - b;

        return (i128)x + (i128)2 * b *
               ((x - a + D - 1) / D);
    }

    // Sum of 1 + getTime(x) over [L, R]
    i128 sumTime(ll L, ll R, ll a, ll b) {
        if (L > R) return 0;

        i128 ans = 0;

        // x <= 0: time = 1
        ll end = min(R, 0LL);

        if (L <= end)
            ans += (i128)(end - L + 1);

        // 1 <= x <= a: time = x + 1
        ll left = max(L, 1LL);
        ll right = min(R, a);

        if (left <= right) {
            i128 cnt = right - left + 1;
            ans += cnt * (left + right + 2) / 2;
        }

        // x > a: time = x + 1 + 2*b*ceil((x-a)/(a-b))
        left = max(L, a + 1);

        if (left <= R) {
            i128 cnt = R - left + 1;

            i128 sumX = cnt * (left + R + 2) / 2;

            ll D = a - b;

            i128 q = floorSum(
                cnt, D, 1, left - a + D - 1
            );

            ans += sumX + (i128)2 * b * q;
        }

        return ans;
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        // Normal movement time
        i128 normal = getTime(d, a, b);

        // Convert jump range into position range
        ll L = (ll)d - r;
        ll R = (ll)d - l;

        // Find first x where 1 + getTime(x) >= normal
        ll low = L, high = R + 1;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (1 + getTime(mid, a, b) >= normal)
                high = mid;
            else
                low = mid + 1;
        }

        ll cut = low;

        // Sum values before the cutoff
        i128 ans = sumTime(L, cut - 1, a, b);

        // Remaining values use normal movement time
        ans += (i128)(R - cut + 1) * normal;

        return (int)(ans % MOD);
    }
};
```

*Generated on: 11/25/2026, 10:23:32 PM*