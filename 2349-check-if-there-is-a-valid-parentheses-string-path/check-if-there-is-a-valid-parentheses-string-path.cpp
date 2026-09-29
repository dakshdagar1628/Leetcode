class Solution {
public:
    int m, n;
    vector<vector<vector<bool>>> vis;

    bool dfs(vector<vector<char>>& g, int i, int j, int bal) {
        if (vis[i][j][bal]) return false;
        vis[i][j][bal] = true;

        bal += (g[i][j] == '(' ? 1 : -1);

        // Invalid prefix
        if (bal < 0) return false;

        // Not enough cells left to close all '('
        if (bal > m - i + n - j - 1) return false;

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (i + 1 < m && dfs(g, i + 1, j, bal))
            return true;

        if (j + 1 < n && dfs(g, i, j + 1, bal))
            return true;

        return false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2) return false;

        // First must be '(' and last must be ')'
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;

        vis.assign(m, vector<vector<bool>>(n,
                    vector<bool>(m + n, false)));

        return dfs(grid, 0, 0, 0);
    }
};