class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0] = 1;
        int cnt = 0, psum = 0 ;
        for(int  i = 0; i < nums.size(); i++)
        {
            psum += nums[i];
            int remove = psum - k;
            cnt += mpp[remove];
            mpp[psum] += 1;
        }
        return cnt;
    }
};