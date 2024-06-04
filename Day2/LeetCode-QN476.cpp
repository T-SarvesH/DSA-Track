class Solution {
public:
    int findComplement(int num) {
        
        int ms = 0;
        int m = num;

        if (num==0)
        return 1;
        
        while(m!=0)
        {
            ms = (ms<<1) | 1;
            m = m>>1;
        }

        return((~num) & ms);
        
    
    }
};