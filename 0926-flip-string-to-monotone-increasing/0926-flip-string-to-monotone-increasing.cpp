class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(string &s, int curr_index, int prev_val) {
        if (curr_index >= n)
            return 0;

        if (dp[curr_index][prev_val] != -1)
            return dp[curr_index][prev_val];

        int flip = INT_MAX;
        int no_flip = INT_MAX;

        if (s[curr_index] == '0') {
            if (prev_val == 0)
                no_flip = solve(s, curr_index + 1, 0);

            flip = 1 + solve(s, curr_index + 1, 1);
        }
        else {
            no_flip = solve(s, curr_index + 1, 1);

            if (prev_val == 0)
                flip = 1 + solve(s, curr_index + 1, 0);
        }

        return dp[curr_index][prev_val] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s) {
        n = s.size();
        dp.assign(n, vector<int>(2, -1));

        return solve(s, 0, 0);
    }
};