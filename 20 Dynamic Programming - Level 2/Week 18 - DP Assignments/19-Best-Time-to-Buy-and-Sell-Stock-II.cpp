//leetcode 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    // Recursive solution
    int solve(vector<int>& prices, int i, int buy) {
        if (i >= prices.size()) 
            return 0;

        int profit = 0;

        if (buy) {
            int buyItProfit = -prices[i] + solve(prices, i + 1, 0);
            int skipProfit = solve(prices, i + 1, 1);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solve(prices, i + 1, 1);
            int skipProfit = solve(prices, i + 1, 0);
            profit = max(sellItProfit, skipProfit);
        }

        return profit;
    }

    // Top-down dynamic programming (memoization)
    int solveTD(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        if (i >= prices.size()) 
            return 0;

        if (dp[i][buy] != -1) 
            return dp[i][buy];

        int profit = 0;

        if (buy) {
            int buyItProfit = -prices[i] + solveTD(prices, i + 1, 0, dp);
            int skipProfit = solveTD(prices, i + 1, 1, dp);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solveTD(prices, i + 1, 1, dp);
            int skipProfit = solveTD(prices, i + 1, 0, dp);
            profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy] = profit;
        return dp[i][buy];
    }

    // Bottom-up dynamic programming (tabulation)
    int solveBU(vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                int profit = 0;
                if (buy) {
                    int buyItProfit = -prices[i] + dp[i + 1][0];
                    int skipProfit = dp[i + 1][1];
                    profit = max(buyItProfit, skipProfit);
                } else {
                    int sellItProfit = prices[i] + dp[i + 1][1];
                    int skipProfit = dp[i + 1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

        // Space-optimized bottom-up dynamic programming
    int solveSO(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, 0)); // Space-optimized: only storing two rows (current and next)

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                int profit = 0;
                if (buy) {
                    int buyItProfit = -prices[i] + dp[1][0];
                    int skipProfit = dp[1][1];
                    profit = max(buyItProfit, skipProfit);
                } else {
                    int sellItProfit = prices[i] + dp[1][1];
                    int skipProfit = dp[1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0]; // Move the current row to the next row
        }

        return dp[0][1]; // Maximum profit starting with a "buy" decision
    }

    
    int maxProfit(vector<int>& prices) {
        // Recursive approach
        // return solve(prices, 0, 1);

        // Top-down DP approach
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solveTD(prices, 0, 1, dp);

        // Bottom-up DP approach
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // return solveBU(prices, dp);

        // Space-optimized DP approach
        return solveSO(prices);
    }
};
