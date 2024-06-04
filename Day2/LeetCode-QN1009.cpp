class Solution {
public:
    int bitwiseComplement(int n) {
        
        
        int ms = 0;
        int m = n;

        if (n==0)
        return 1;
        
        while(m!=0)
        {
            ms = (ms<<1) | 1;
            m = m>>1;
        }

        return((~n) & ms);
        
    }
};