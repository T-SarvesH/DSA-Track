class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        
        int count = 0;

        while(start!=0 || goal!=0)
        {
            int a1 = start & 1;
            int a2 = goal & 1;

            if(a1!=a2)
            count++;
            
            start = start>>1;
            goal = goal>>1;
        }
        return count;
    }
};