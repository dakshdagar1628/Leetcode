class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1, sum2 = 0;
        int num;
        int n = nums.size();
        sum1 = n*(n+1)/2;
        for(int i = 0; i < n; i++)
        {
            sum2 = sum2 +nums[i];
        }
        num = sum1 - sum2;
        return num;

    }
};