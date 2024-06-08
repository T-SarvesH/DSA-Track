class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
            int con = 0;

            for(int i=0; i<nums.size(); i++)
            con^=nums[i];

            return con;
    }
};