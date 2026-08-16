class Solution {
public:
 set<vector<int>>ans;
   void solve(vector<int>& nums,int n,int ind, set<vector<int>>&ans,vector<int>&temp)
    {
        //base-case
        if(ind==n)
        {
            ans.insert(temp);
            return;
        }
        
        //take
        temp.push_back(nums[ind]);
        solve(nums,n,ind+1,ans,temp);
        temp.pop_back();
        //not_take 
        solve(nums,n,ind+1,ans,temp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         int n = nums.size();
       
        vector<int>temp;
        solve(nums,n,0,ans,temp);

        vector<vector<int>>v;
        for(auto it : ans)
        {
            if(it.size()>1)
            {
                bool  value = true;
              for(int i=1;i<it.size();i++)
              {
                if(it[i-1]>it[i])
                {
                    value = false;
                }
              }

              if(value == true)
              {
                v.push_back(it);
              }
            }
        }

        return v;
    }
};