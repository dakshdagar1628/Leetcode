bool possible(vector<int>& arr, int day, int m, int k) {
    int cnt = 0;
    int nb = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= day) {
            cnt++;
        } 
        else {
            nb += cnt / k;
            cnt = 0;
        }
    }

    // Check the last consecutive group
    nb += cnt / k;

    return nb >= m;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        // Need at least m*k flowers
        long long val = 1LL * m * k;

        if (val > bloomDay.size())
            return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Find minimum and maximum bloom days
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        // Binary search for minimum possible day
        int low = mini;
        int high = maxi;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                // We can make m bouquets.
                // Try an earlier day.
                high = mid - 1;
            } 
            else {
                // Not enough flowers yet.
                // Need more days.
                low = mid + 1;
            }
        }

        return low;
    }
};