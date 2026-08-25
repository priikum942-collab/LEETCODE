class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1;;i++)
        {
            int num = k*i;
            bool found = false;
            for(int j = 0;j<n;j++)
            {
                if(num == nums[j])
                {
                    found = true;
                }
            }

            if(!found)
            {
                ans = num;
                break;
            }
        }

        return ans;
    }
};