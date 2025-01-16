//leetcode 1406. Stone Game III

class Solution {
public:
    // Recursive Solution
    int solve(vector<int>& sv, int i) {
        if (i >= sv.size()) return 0; // Base case: No more stones left

        int ans = INT_MIN;
        int total = 0;

        for (int X = 1; X <= 3; ++X) {
            if (i + X - 1 >= sv.size()) break; // Break if out of bounds
            total += sv[i + X - 1];
            ans = max(ans, total - solve(sv, i + X)); // A-B difference logic
        }

        return ans;
    }

    // Top-Down (Memoized) Solution
    int solveTD(vector<int>& sv, int i, vector<int>& dp) {
        if (i >= sv.size()) return 0; // Base case

        if (dp[i] != -1) return dp[i]; // Return already calculated result

        int ans = INT_MIN;
        int total = 0;

        for (int X = 1; X <= 3; ++X) {
            if (i + X - 1 >= sv.size()) break; // Out of bounds
            total += sv[i + X - 1];
            ans = max(ans, total - solveTD(sv, i + X, dp));
        }

        return dp[i] = ans; // Store result for memoization
    }

    // Bottom-Up (Iterative) Solution
    int solveBU(vector<int>& sv) {
        vector<int> dp(sv.size() + 1, 0); // dp array initialized with 0

        for (int i = sv.size() - 1; i >= 0; --i) {
            int ans = INT_MIN;
            int total = 0;

            for (int X = 1; X <= 3; ++X) {
                if (i + X - 1 >= sv.size()) break; // Out of bounds
                total += sv[i + X - 1];
                ans = max(ans, total - dp[i + X]);
            }

            dp[i] = ans; // Store the result
        }

        return dp[0]; // Result for the entire array
    }

    // Main function
    string stoneGameIII(vector<int>& stoneValue) {
        //int ans = solve(stoneValue, 0); // Recursive Solution

        vector<int> dp(stoneValue.size() + 1, -1);
        // int ans = solveTD(stoneValue, 0, dp); // Top-Down Solution

        int ans = solveBU(stoneValue); // Bottom-Up Solution

        if (ans > 0) return "Alice"; // Alice wins
        if (ans < 0) return "Bob";   // Bob wins
        return "Tie";                // It's a tie
    }
};
