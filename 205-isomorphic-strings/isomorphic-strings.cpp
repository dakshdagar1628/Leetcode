class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char m_s[128] = {0};
        char m_ss[128] = {0};
        for(int i = 0; i < s.size(); ++i)
        {
            if(m_s[s[i]] != m_ss[t[i]])
            return false;
            m_s[s[i]] = i + 1;
            m_ss[t[i]] = i + 1;
        }
        return true;

    }
};