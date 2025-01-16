//leetcode 312.Burst Balloons

class Solution {
public:
    // Recursive Solution
    int solve(vector<int>& nums, int start, int end) {
        if (start > end) return 0; // Base case

        int coins = INT_MIN;

        for (int i = start; i <= end; ++i) {
            coins = max(coins,
                        nums[start - 1] * nums[i] * nums[end + 1]
                        + solve(nums, start, i - 1)
                        + solve(nums, i + 1, end));
        }

        return coins;
    }

    // Top-Down (Memoized) Solution
    int solveTD(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start > end) return 0; // Base case

        if (dp[start][end] != -1) return dp[start][end]; // Return memoized result

        int coins = INT_MIN;

        for (int i = start; i <= end; ++i) {
            coins = max(coins,
                        nums[start - 1] * nums[i] * nums[end + 1]
                        + solveTD(nums, start, i - 1, dp)
                        + solveTD(nums, i + 1, end, dp));
        }

        return dp[start][end] = coins; // Store result
    }

    // Bottom-Up (Iterative) Solution
    int solveBU(vector<int>& nums) {
        int n = nums.size() - 2; // Excluding the added 1's at both ends
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for (int start = n; start >= 1; --start) {
            for (int end = start; end <= n; ++end) {
                int coins = INT_MIN;

                for (int i = start; i <= end; ++i) {
                    coins = max(coins,
                                nums[start - 1] * nums[i] * nums[end + 1]
                                + dp[start][i - 1]
                                + dp[i + 1][end]);
                }

                dp[start][end] = coins; // Store result
            }
        }

        return dp[1][n]; // Result for the entire array
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); // Add 1 at the beginning
        nums.insert(nums.end(), 1);   // Add 1 at the end

        // Recursive Solution
        // return solve(nums, 1, nums.size() - 2);

        // Top-Down (Memoized) Solution
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        // return solveTD(nums, 1, nums.size() - 2, dp);

        // Bottom-Up (Iterative) Solution
        return solveBU(nums);
    }
};
