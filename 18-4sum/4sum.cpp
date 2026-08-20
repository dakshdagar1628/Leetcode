class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Minimum possible sum for this i
            long long minSum = (long long)nums[i]
                             + nums[i + 1]
                             + nums[i + 2]
                             + nums[i + 3];

            if (minSum > target)
                break;

            // Maximum possible sum for this i
            long long maxSum = (long long)nums[i]
                             + nums[n - 1]
                             + nums[n - 2]
                             + nums[n - 3];

            if (maxSum < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Minimum possible sum for this i,j
                long long minSum2 = (long long)nums[i]
                                  + nums[j]
                                  + nums[j + 1]
                                  + nums[j + 2];

                if (minSum2 > target)
                    break;

                // Maximum possible sum for this i,j
                long long maxSum2 = (long long)nums[i]
                                  + nums[j]
                                  + nums[n - 1]
                                  + nums[n - 2];

                if (maxSum2 < target)
                    continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {

                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[k]
                                  + nums[l];

                    if (sum < target) {
                        k++;
                    }
                    else if (sum > target) {
                        l--;
                    }
                    else {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[k],
                            nums[l]
                        });

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1])
                            k++;

                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return ans;
    }
};