class Solution {
public:
    int maxDifference(string s) {
        vector<int> res(26, 0);
        for (char &ch : s) {
            res[ch - 'a']++;
        }
        int mo = 0;
        int me = s.size() + 1;
        for (int i = 0; i < 26; i++) {
            if (res[i] == 0)
                continue;
            else if (res[i] % 2 == 0)
                me = min(me, res[i]);
            else {
                mo = max(mo, res[i]);
            }
        }
        return mo - me;
    }
};