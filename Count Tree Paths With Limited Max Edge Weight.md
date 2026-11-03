## 01. Count Tree Paths With Limited Max Edge Weight

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/possible-paths--141628/1)

### Problem Description

**Task:** Given a weighted tree with n nodes, numbered from 1 to n and n - 1 edges, where each edge is represented as [u, v, w] indicating an edge between nodes u and v with weight w.You are also given an array queries[], where each queries[i] represents a maximum allowed edge weight.For each query x, find the number of distinct paths in the tree such that the maximum edge weight along the path is less than or equal to x.Return an array containing the number of valid paths for each query.Note: A path from node u to node v and the path from node v to node u are considered the same path. A path must contain at least one edge. A path from a node to itself is not considered.Examples:Input: n = 3, edges[][] = [[1, 2, 1], [2, 3, 4]], queries[] = [3]

#### Examples

##### Example 1

- **Output:**
```text
[1, 3, 4]
```
- **Explanation:** For x = 1, only the edge [2, 3, 1] satisfies the condition. Therefore, the only valid path is 2 - > 3, giving an answer of 1. For x = 3, the edges [2, 3, 1] and [1, 2, 3] can be used. They form three valid paths: 1 - > 2, 2 - > 3, and 1 - > 3. For x = 5, the edges with weights 1, 3, and 4 can be used. They form four valid paths: 1 - > 2, 2 - > 3, 1 - > 3, and 5 - > 7.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(nlogn + qlogn)
- **Expected Auxiliary Space Complexity:** O(n)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-03 12:40:25
- **Status:** Correct
- **Marks:** 8

```cpp
class Solution {
public:

    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    long long unite(int u, int v) {

        u = find(u);
        v = find(v);

        if (u == v)
            return 0;

        if (sz[u] < sz[v])
            swap(u, v);

        long long added = 1LL * sz[u] * sz[v];

        parent[v] = u;
        sz[u] += sz[v];

        return added;
    }

    vector<int> maximumWeight(
        int n,
        vector<vector<int>> edges,
        vector<int>& queries
    ) {

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        // Sort edges by weight
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        // Store query and original index
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());

        long long total = 0;
        int j = 0;

        for (auto &query : q) {

            int x = query.first;
            int idx = query.second;

            // Process all eligible edges
            while (j < edges.size() &&
                   edges[j][2] <= x) {

                total += unite(edges[j][0], edges[j][1]);

                j++;
            }

            ans[idx] = total;
        }

        return ans;
    }
};
```

*Generated on: 11/3/2026, 12:41:45 PM*