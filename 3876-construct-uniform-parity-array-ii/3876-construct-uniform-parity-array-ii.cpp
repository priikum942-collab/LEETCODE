class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        //to make it odd 
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,nums1[i]);
        }


        if(mini%2 !=0)
        {
            return true;
        }
        //check if all even 
        bool val = true;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2!=0)
            {
                val = false;
            }
        }
        
        if(val)
        {
            return true;
        }

        return false;
    }
};