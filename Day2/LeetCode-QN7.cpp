class Solution {
public:
    int reverse(int x) {
        
        int maxi = pow(2,31)-1;
        int mini = -1*pow(2,31);
        int ans  = 0;
        int i = 0;

        while(x!=0)
        {
            int k = x%10;

            if(ans>(maxi/10) || ans<(mini/10))
            return 0;

            ans = k + ans*10;
            x = x/10;
            
        }
        
        return ans;
    }
};