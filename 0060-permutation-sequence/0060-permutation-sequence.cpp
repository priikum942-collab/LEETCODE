class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        string ans = "";
        //find factorial 
        int fact = 1;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
            fact *= i;
        }
        //as 0-based ind 
        k--;
        int size = n-1;
        while(size >=0)
        {
            fact /= size + 1; //24/4 = 6
            int ind = k/fact;
            ans += to_string(nums[ind]);

            nums.erase(nums.begin() + ind);

            k %= fact;
            size--;
        }


        return ans;
    }
};