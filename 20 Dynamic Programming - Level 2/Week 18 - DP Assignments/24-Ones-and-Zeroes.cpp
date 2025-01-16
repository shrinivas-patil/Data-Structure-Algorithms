//leetcode 474. Ones and Zeroes

class Solution {
public:
    // Function to convert strings to pairs of (number of 0's, number of 1's)
    void convertStrsToNumStrs(vector<string>& strs, vector<pair<int, int>>& numStrs) {
        for (auto& str : strs) {
            int zeros = 0, ones = 0;
            for (auto& ch : str) {
                if (ch == '0') ++zeros;
                else ++ones;
            }
            numStrs.push_back({zeros, ones});
        }
    }

    // Recursive Solution
    int solve(vector<pair<int, int>>& numStrs, int i, int m, int n) {
        if (i == numStrs.size()) return 0;

        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if (m - zeros >= 0 && n - ones >= 0) 
            include = 1 + solve(numStrs, i + 1, m - zeros, n - ones);
        exclude = solve(numStrs, i + 1, m, n);
        return max(include, exclude);
    }
    // Top-Down DP (Memoization)
    int solveTD(vector<pair<int, int>>& numStrs, int i, int m, int n, vector<vector<vector<int>>>& dp) {
        if (i == numStrs.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;
        if (m - zeros >= 0 && n - ones >= 0) 
            include = 1 + solveTD(numStrs, i + 1, m - zeros, n - ones, dp);
        exclude = solveTD(numStrs, i + 1, m, n, dp);
        return dp[i][m][n] = max(include, exclude);
    }

    // Bottom-Up DP (Tabulation)
    int solveBU(vector<pair<int, int>>& numStrs, int m, int n) {
        vector<vector<vector<int>>> dp(numStrs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = numStrs.size() - 1; i >= 0; --i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    int zeros = numStrs[i].first;
                    int ones = numStrs[i].second;
                    int include = 0, exclude = 0;
                    if (j - zeros >= 0 && k - ones >= 0) 
                        include = 1 + dp[i + 1][j - zeros][k - ones];                    
                    exclude = dp[i + 1][j][k];
                    dp[i][j][k] = max(include, exclude);
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> numStrs; // (number of 0's, number of 1's)
        convertStrsToNumStrs(strs, numStrs);

        // Recursive Solution
        return solve(numStrs, 0, m, n);

        // Top-Down DP (Memoization)
        // vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        // return solveTD(numStrs, 0, m, n, dp);

        // Bottom-Up DP (Tabulation)
        // return solveBU(numStrs, m, n);
    }
};
