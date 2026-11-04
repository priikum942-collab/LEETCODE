class Solution {
public:
    int minMoves(vector<int>& nums) {
        //find max element 

        int maxi = INT_MIN;

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,nums[i]);
        }

        int moves = 0;
        for(int i=0;i<n;i++)
        {
            moves += maxi - nums[i];
        }


        return moves;

    }
};