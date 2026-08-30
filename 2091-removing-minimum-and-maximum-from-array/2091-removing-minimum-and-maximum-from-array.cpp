class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min_ind = 0;
        int max_ind = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[min_ind])
                min_ind = i;

            if (nums[i] > nums[max_ind])
                max_ind = i;
        }

        int left = min(min_ind, max_ind) + 1;
        int right = n - max(min_ind, max_ind);

        int both_left = max(min_ind, max_ind) + 1;
        int both_right = n - min(min_ind, max_ind);

        return min({both_left, both_right, left + right});
    }
};