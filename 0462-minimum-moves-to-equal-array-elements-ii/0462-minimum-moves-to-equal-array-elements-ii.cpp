class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //sort them 
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int mid = n/2;

        int num = nums[mid];

        int moves = 0;
        for(int i=0;i<n;i++)
        {
            moves += abs(nums[i]-num);
        }


        return moves;
    }
};