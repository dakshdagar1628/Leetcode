class Solution {
public:
    string longestPalindrome(string s) {

        string ans = "";
		
		for (int i = 0; i < s.size(); i++) {
			
			for (int j = i; j < s.size(); j++) {
				
				bool isPalindrome = true;
				
				int left = i;
				int right = j;
				
				while (left < right) {
					
					if (s[left] != s[right]) {
						isPalindrome = false;
						break;
					}
					
					left++;
					right--;
				}
				
				if (isPalindrome && (j - i + 1 > ans.size())) {
					ans = s.substr(i, j - i + 1);
				}
			}
		}
		
		return ans;
    }
};