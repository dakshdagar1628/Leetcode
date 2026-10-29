class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n), depth(n), sz(n, 1), heavy(n, -1);
        vector<int> head(n), pos(n), rev(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            int best = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > best) {
                    best = sz[v];
                    heavy[u] = v;
                }
            }
        };

        function<void(int, int)> decompose = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer;
            rev[timer++] = u;

            if (heavy[u] != -1)
                decompose(heavy[u], h);

            for (int v : adj[u]) {
                if (v != parent[u] && v != heavy[u])
                    decompose(v, v);
            }
        };

        dfs(0, -1);
        decompose(0, 0);

        vector<int> seg(4 * n, 0);

        function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = 1 << (s[rev[l]] - 'a');
                return;
            }
            int m = (l + r) / 2;
            build(node * 2, l, m);
            build(node * 2 + 1, m + 1, r);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };

        function<void(int, int, int, int, int)> update =
            [&](int node, int l, int r, int idx, int val) {
                if (l == r) {
                    seg[node] = val;
                    return;
                }
                int m = (l + r) / 2;
                if (idx <= m)
                    update(node * 2, l, m, idx, val);
                else
                    update(node * 2 + 1, m + 1, r, idx, val);
                seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
            };

        function<int(int, int, int, int, int)> query =
            [&](int node, int l, int r, int ql, int qr) -> int {
                if (ql <= l && r <= qr) return seg[node];
                int m = (l + r) / 2;
                int res = 0;
                if (ql <= m) res ^= query(node * 2, l, m, ql, qr);
                if (qr > m) res ^= query(node * 2 + 1, m + 1, r, ql, qr);
                return res;
            };

        build(1, 0, n - 1);

        auto pathXor = [&](int u, int v) {
            int mask = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);
                mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            mask ^= query(1, 0, n - 1, pos[u], pos[v]);
            return mask;
        };

        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int v;
                ss >> v;
                int mask = pathXor(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};