class Solution {
public:
    int minMoves(vector<int>& nums) {
        //find min value 
        int mini = INT_MAX;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            mini = min(mini,nums[i]);
        }

        int moves = 0;
        for(int i=0;i<n;i++)
        {
            moves += nums[i] - mini;
        }

        return moves;
    }
};