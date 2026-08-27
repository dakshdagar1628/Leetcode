class Solution {
public:

    int findMax(vector<int>& v) {
        int maxi = INT_MIN;

        for (int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }

    long long calculateTotalHours(vector<int>& v, int hourly) {
        long long totalH = 0;

        for (int i = 0; i < v.size(); i++) {
            totalH += (v[i] + (long long)hourly - 1) / hourly;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = findMax(piles);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};