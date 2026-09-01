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
        if(mpp1 == mpp2)
        return true;
        else
        return false;
    }
};