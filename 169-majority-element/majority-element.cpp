class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;
        int cnt = 0;
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                cnt = 1;
                ele = nums[i];
            } else if (nums[i] != ele)
                cnt--;
            else
                cnt++;
        }
        for (int j = 0; j < nums.size(); j++) {
            
            if (ele == nums[j])
                cnt1++;
        }
        if (cnt1 > (nums.size() / 2))
        return ele;
        else
        return -1;
    }
};