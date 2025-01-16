//leetcode 1140. Stone Game II
class Solution {
public:
    // Recursive Solution
    int solve(vector<int>& piles, int i, int M, bool alice) {
        if (i >= piles.size()) return 0; // Base case

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; ++X) {
            if (i + X - 1 >= piles.size()) break; // Out of bounds
            total += piles[i + X - 1];
            if (alice) {
                ans = max(ans, total + solve(piles, i + X, max(X, M), !alice));
            } else {
                ans = min(ans, solve(piles, i + X, max(X, M), !alice));
            }
        }

        return ans;
    }

    // Top-Down (Memoized) Solution
    int solveTD(vector<int>& piles, int i, int M, bool alice, vector<vector<vector<int>>>& dp) {
        if (i >= piles.size()) return 0; // Base case

        if (dp[i][M][alice] != -1) return dp[i][M][alice]; // Return memoized result

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for (int X = 1; X <= 2 * M; ++X) {
            if (i + X - 1 >= piles.size()) break; // Out of bounds
            total += piles[i + X - 1];
            if (alice) {
                ans = max(ans, total + solveTD(piles, i + X, max(X, M), !alice, dp));
            } else {
                ans = min(ans, solveTD(piles, i + X, max(X, M), !alice, dp));
            }
        }

        return dp[i][M][alice] = ans; // Store result
    }

    // Bottom-Up (Iterative) Solution
    int solveBU(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = n; M >= 1; --M) {
                for (int alice = 0; alice <= 1; ++alice) {
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0;

                    for (int X = 1; X <= 2 * M; ++X) {
                        if (i + X - 1 >= n) break; // Out of bounds
                        total += piles[i + X - 1];
                        if (alice) {
                            ans = max(ans, total + dp[i + X][max(X, M)][!alice]);
                        } else {
                            ans = min(ans, dp[i + X][max(X, M)][!alice]);
                        }
                    }

                    dp[i][M][alice] = ans;
                }
            }
        }

        return dp[0][1][1]; // Starting at index 0, M = 1, Alice's turn
    }

    int stoneGameII(vector<int>& piles) {
        // Recursive Solution
        // return solve(piles, 0, 1, true);

        // Top-Down (Memoized) Solution
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        // return solveTD(piles, 0, 1, true, dp);

        // Bottom-Up (Iterative) Solution
        return solveBU(piles);
    }
};
