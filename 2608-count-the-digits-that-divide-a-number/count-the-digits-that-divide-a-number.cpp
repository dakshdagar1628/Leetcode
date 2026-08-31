class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int o = num;
        int t = num;
        while (t > 0) {
            int ld = t % 10;
            if ((o % ld) == 0)
                cnt++;
            t = t / 10;
        }
        return cnt;
    }
};