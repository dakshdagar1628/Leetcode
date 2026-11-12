class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pf = 1;
        int sf = 1;
        int ans = INT_MIN;
        for(int i = 0; i <nums.size(); i++)
        {
           if(pf==0)
           pf = 1;
           if(sf==0)
           sf = 1;
           pf *= nums[i];
           sf *= nums[nums.size() - 1 - i];
           ans = max(ans,max(pf,sf));
        }
        return ans;
    }
};