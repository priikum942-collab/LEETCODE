class Solution {
public:
    vector<int> memo;

    int solve(int num) {
        if (num == 0)
            return 0;

        if (memo[num] != -1)
            return memo[num];

        int ans = INT_MAX;

        for (int i = 1; i * i <= num; i++) {
            int sq = i * i;

            ans = min(ans, 1 + solve(num - sq));
        }

        return memo[num] = ans;
    }

    int numSquares(int n) {
        memo.resize(n + 1, -1);

        return solve(n);
    }
};