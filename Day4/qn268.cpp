class Solution {
public:
    int missingNumber(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        int set = 0;

        for (int p = 0; p < nums.size(); p++) {
            int con = nums[p] | 0;

            if (set != con)
                break;

            set++;
        }

        return set;
    }
};