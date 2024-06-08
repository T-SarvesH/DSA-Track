class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int ans;
        std::sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i+1<nums.size() && (nums[i]^nums[i+1])==0)
            {
               ans = nums[i];
               break;
            }
        }
        return ans;   
    }
};