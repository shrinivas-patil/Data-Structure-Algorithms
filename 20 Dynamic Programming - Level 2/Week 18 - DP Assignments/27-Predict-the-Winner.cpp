//leetcode 486. Predict the Winner

class Solution {
public:
    // Recursive Approach
    int solve(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];       
        int diffByStart = nums[start] - solve(nums, start + 1, end);
        int diffByEnd = nums[end] - solve(nums, start, end - 1);       
        return max(diffByStart, diffByEnd);
    }

    // Top-Down Memoization
    int solveTD(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start == end) return nums[start];
        if (dp[start][end] != -1) return dp[start][end];
        int diffByStart = nums[start] - solveTD(nums, start + 1, end, dp);
        int diffByEnd = nums[end] - solveTD(nums, start, end - 1, dp);
        dp[start][end] = max(diffByStart, diffByEnd);
        return dp[start][end];
    }

    // Bottom-Up Tabulation
    int solveBU(vector<int>& nums, vector<vector<int>>& dp) {
        // Base case: Single elements
        for (int i = 0; i < nums.size(); ++i) dp[i][i] = nums[i];
        int i = nums.size();
        // Fill DP table for all subarray lengths
        for (int start = nums.size()-1; start >=0; --start) {
            for (int end = i; end < nums.size(); ++end) {
                int diffByStart = nums[start] - dp[start + 1][end];
                int diffByEnd = nums[end] - dp[start][end - 1];
                dp[start][end] = max(diffByStart, diffByEnd);
            }
            --i;
        }

        return dp[0][nums.size() - 1];
    }

    // Main Function
    bool predictTheWinner(vector<int>& nums) {
        // Recursive
        // return solve(nums, 0, nums.size() - 1) >= 0;

        // Top-Down
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        // return solveTD(nums, 0, nums.size() - 1, dp) >= 0;

        // Bottom-Up
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return solveBU(nums,dp) >= 0;
    }
};
