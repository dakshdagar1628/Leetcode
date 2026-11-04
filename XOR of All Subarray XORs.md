## 01. XOR of All Subarray XORs

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/game-of-xor1541/1)

### Problem Description

**Task:** Given an integer array arr[], find the XOR of the XOR values of all possible non-empty subarrays of the array.Examples:Input: arr[] = [1, 2, 3]

#### Examples

##### Example 1

- **Output:**
```text
2 xor[1] = 1 xor[1, 2] = 3 xor[2, 3] = 1 xor[1, 2, 3] = 0 xor[2] = 2 xor[3] = 3 Result: 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
```

##### Example 2

- **Input:**
```text
arr[] = [1, 2]
```
- **Output:**
```text
0 xor[1] = 1 xor[1, 2] = 3 xor[2] = 2 Result: 1 ^ 3 ^ 2 = 0
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-04 23:55:44
- **Status:** Correct
- **Marks:** 4

```cpp
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        if (n % 2 == 0) return 0;

        for (int i = 0; i < n; i += 2) {
            ans ^= arr[i];
        }

        return ans;
    }
};
```

*Generated on: 11/5/2026, 12:15:06 AM*