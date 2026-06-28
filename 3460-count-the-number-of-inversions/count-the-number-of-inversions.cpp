class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        vector<int> need(n, -1);

        for (auto &x : requirements)
            need[x[0]] = x[1];

        int maxInv = 0;
        for (auto &x : requirements)
            maxInv = max(maxInv, x[1]);

        vector<vector<int>> dp(n + 1, vector<int>(maxInv + 1, 0));

        dp[0][0] = 1;

        for (int len = 1; len <= n; len++) {

            for (int inv = 0; inv <= maxInv; inv++) {

                long long ways = 0;

                for (int add = 0; add <= min(inv, len - 1); add++) {

                    ways += dp[len - 1][inv - add];
                    ways %= MOD;
                }

                dp[len][inv] = ways;
            }

            if (need[len - 1] != -1) {

                for (int inv = 0; inv <= maxInv; inv++) {

                    if (inv != need[len - 1])
                        dp[len][inv] = 0;
                }
            }
        }

        long long ans = 0;

        for (int inv = 0; inv <= maxInv; inv++)
            ans = (ans + dp[n][inv]) % MOD;

        return ans;
    }
};