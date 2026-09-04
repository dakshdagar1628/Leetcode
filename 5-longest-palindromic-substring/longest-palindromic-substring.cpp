class Solution {
public:
    string longestPalindrome(string s) {

        int maxlen = 0;
        int sp = 0;

        for (int i = 0; i < s.size(); i++) {

            for (int j = i; j < s.size(); j++) {

                int left = i;
                int right = j;
                bool palindrome = true;

                while (left < right) {

                    if (s[left] != s[right]) {
                        palindrome = false;
                        break;
                    }

                    left++;
                    right--;
                }

                if (palindrome) {

                    int len = j - i + 1;

                    if (len > maxlen) {
                        maxlen = len;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxlen);
    }
};