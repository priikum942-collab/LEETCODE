class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(k+i>n) 
            {
                break;
            }
            unordered_set<int>st;
            for(int j = i;j<i+k;j++)
            {
                st.insert(nums[j]);
            }

            for(auto it : st)
            {
                mp[it]++;
            }
        }

        int maxi = -1;
        for(auto it : mp)
        {
            if(maxi < it.first && it.second == 1)
            {
                maxi = it.first;
            }

        }
       
        return maxi;
    }
};