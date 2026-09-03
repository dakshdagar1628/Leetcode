class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int r = nums[i]*nums[i];
            res.push_back(r);
            r = 0;
        }
        sort(res.begin(), res.end());
        return res;
    }
};