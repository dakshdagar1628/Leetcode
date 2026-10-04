class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' can act as ')'
                high++;  // '*' can act as '('
            }

            // We can't have negative possible open brackets
            if (high < 0)
                return false;

            // Minimum can't go below 0
            low = max(low, 0);
        }

        return low == 0;
    }
};