class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while (!q.empty() && !found) {
            int n = q.size();

            while (n--) {
                string cur = q.front();
                q.pop();

                int bal = 0;
                bool valid = true;

                for (char c : cur) {
                    if (c == '(')
                        bal++;
                    else if (c == ')') {
                        bal--;
                        if (bal < 0) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (valid && bal == 0) {
                    ans.push_back(cur);
                    found = true;
                    continue;
                }

                if (found) continue;

                for (int i = 0; i < cur.size(); i++) {
                    // Don't remove letters
                    if (cur[i] != '(' && cur[i] != ')')
                        continue;

                    // Avoid generating duplicates
                    if (i > 0 && cur[i] == cur[i - 1])
                        continue;

                    string next = cur.substr(0, i) + cur.substr(i + 1);

                    if (!vis.count(next)) {
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return ans;
    }
};