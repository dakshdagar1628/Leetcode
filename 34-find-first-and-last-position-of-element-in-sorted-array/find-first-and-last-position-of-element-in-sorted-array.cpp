int UpperBound(vector<int> &arr, int target) {
        int low = 0; int high = arr.size() - 1;
            int ans = arr.size();
            while(low <= high)
            {
                int mid  = (low + high)/2;
                if(arr[mid] > target)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return ans;
        
    }
    int lowerBound(vector<int>& arr, int target) {
        int low = 0; int high = arr.size() - 1;
        int ans = arr.size();
        while(low <= high)
        {
            int mid  = (low + high)/2;
            if(arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
        
    }
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        if(lb == nums.size() || nums[lb] != target)
        return{-1, -1};
        else
        return{lb, UpperBound(nums, target) - 1};
    }
};