class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        vector<int> temp1;
        vector<int> temp2(n);
        // creating max array
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            temp1.push_back(maxi);
        }
        for (int j = n - 1; j >= 0; j--) {
            mini = min(mini, nums[j]);
            temp2[j] = mini;
        }
        for (int i = 0; i < n; i++) {
            int diff = (temp1[i] - temp2[i]);
            if (diff <= k) {
                return i;
            }
        }
        return -1;
    }
};