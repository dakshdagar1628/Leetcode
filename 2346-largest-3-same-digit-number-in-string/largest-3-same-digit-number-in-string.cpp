class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        char maxi = ' ';
        for (int i = 2; i < n; i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2])
                maxi = max(maxi, num[i]);
        }
        if (maxi == ' ')
            return "";
        return string(3, maxi);
    }
};