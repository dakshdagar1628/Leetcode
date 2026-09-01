class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>mpp1;
        map<char, int>mpp2;
        for(const auto &el:s)
        {
            mpp1[el]++;
        }
        for(const auto &el:t)
        {
            mpp2[el]++;
        }
        return mpp1 == mpp2;
    }
};