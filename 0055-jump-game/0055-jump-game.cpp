class Solution {
public:
    vector<int> t;
    int n;

    bool solve(vector<int>& nums, int idx) {
        if (idx >= n - 1)
            return true;

        if (t[idx] != -1)
            return t[idx];

        for (int i = 1; i <= nums[idx]; i++) {
            if (solve(nums, idx + i))
                return t[idx] = true;
        }

        return t[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        t.assign(n, -1);
        return solve(nums, 0);
    }
};