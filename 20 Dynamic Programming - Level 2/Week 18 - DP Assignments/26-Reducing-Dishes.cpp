//leetcode 1402. Reducing Dishes

class Solution {
public:
    // Recursive approach
    int solve(vector<int>& sat, int i, int time) {
        if (i == sat.size()) return 0;
        // Include the current dish
        int includeLikeTimeCoeff = time * sat[i] + solve(sat, i + 1, time + 1);
        // Exclude the current dish
        int excludeLikeTimeCoeff = solve(sat, i + 1, time);
        // Return the maximum satisfaction
        return max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
    }

    // Top-down (memoized) approach
    int solveTD(vector<int>& sat, int i, int time, vector<vector<int>>& dp) {
        if (i == sat.size()) return 0;
        if (dp[i][time] != -1) return dp[i][time];
        // Include the current dish
        int includeLikeTimeCoeff = time * sat[i] + solveTD(sat, i + 1, time + 1, dp);
        // Exclude the current dish
        int excludeLikeTimeCoeff = solveTD(sat, i + 1, time, dp);
        // Store and return the maximum satisfaction
        return dp[i][time] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
    }

    // Bottom-up (iterative) approach
    int solveBU(vector<int>& sat) {
        int n = sat.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0)); // DP table

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n; j >= 1; --j) {
                // Include the current dish
                int includeLikeTimeCoeff = j * sat[i] + dp[i + 1][j + 1];
                // Exclude the current dish
                int excludeLikeTimeCoeff = dp[i + 1][j];
                // Store the maximum satisfaction
                dp[i][j] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
            }
        }
        return dp[0][1]; // Maximum satisfaction starting with time = 1
    }

    // Main function
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end()); // Sort the satisfaction array

        // Recursive approach
        // return solve(satisfaction, 0, 1);

        // Top-down (memoized) approach
        // vector<vector<int>> dp(satisfaction.size(), vector<int>(satisfaction.size() + 1, -1));
        // return solveTD(satisfaction, 0, 1, dp);

        // Bottom-up (iterative) approach
        return solveBU(satisfaction);
    }
};
