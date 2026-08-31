class Solution {
public:
    int differenceOfSums(int n, int m) {
        int nsum = 0;
        int sum = 0;
        for(int i = 0; i <= n; i++)
        {
            if((i%m) != 0)
            {
              nsum = nsum + i;
            }
            else
            {
             sum = sum + i;
            } 
        }
        return  nsum - sum;
    }
};