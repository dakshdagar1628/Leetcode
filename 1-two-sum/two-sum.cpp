class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            sum = target - num;
            if (mpp.find(sum) != mpp.end()) {
                return {mpp[sum], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};