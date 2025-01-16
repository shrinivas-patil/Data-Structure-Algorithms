//leetcode 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    // Recursive solution
    int solveRE(vector<int>& prices, int i, int buy, int&fee) {
        if (i >= prices.size()) return 0;

        int profit = 0;
        if (buy) {
            int buyItProfit = -prices[i] + solveRE(prices, i + 1, 0, fee);
            int skipProfit = solveRE(prices, i + 1, 1, fee);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solveRE(prices, i + 1, 1, fee)- fee;//TXN completed
            int skipProfit = solveRE(prices, i + 1, 0, fee);
            profit = max(sellItProfit, skipProfit);
        }

        return profit;
    }

    // Top-down dynamic programming (memoization)
    int solveTD(vector<int>& prices, int i, int buy, vector<vector<int>>& dp, int&fee) {
        if (i >= prices.size()) 
            return 0;

        if (dp[i][buy] != -1) 
            return dp[i][buy];

        int profit = 0;

        if (buy) {
            int buyItProfit = -prices[i] + solveTD(prices, i + 1, 0, dp, fee);
            int skipProfit = solveTD(prices, i + 1, 1, dp, fee);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solveTD(prices, i + 1, 1, dp, fee)- fee;
            int skipProfit = solveTD(prices, i + 1, 0, dp, fee);
            profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy] = profit;
        return dp[i][buy];
    }

    // Bottom-up dynamic programming (tabulation)
    int solveBU(vector<int>& prices, vector<vector<int>>& dp, int&fee) {
        int n = prices.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                int profit = 0;
                if (buy) {
                    int buyItProfit = -prices[i] + dp[i + 1][0];
                    int skipProfit = dp[i + 1][1];
                    profit = max(buyItProfit, skipProfit);
                } else {
                    int sellItProfit = prices[i] + dp[i + 1][1] - fee ;
                    int skipProfit = dp[i + 1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

        // Space-optimized bottom-up dynamic programming
    int solveSO(vector<int>& prices, vector<vector<int>>&dp, int&fee) {
        int n = prices.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy < 2; ++buy) {
                int profit = 0;
                if (buy) {
                    int buyItProfit = -prices[i] + dp[1][0];
                    int skipProfit = dp[1][1];
                    profit = max(buyItProfit, skipProfit);
                } else {
                    int sellItProfit = prices[i] + dp[1][1] - fee;
                    int skipProfit = dp[1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0]; // Move the current row to the next row
        }

        return dp[0][1]; // Maximum profit starting with a "buy" decision
    }

    
    int maxProfit(vector<int>& prices, int fee) {
        // Recursive approach
        // return solveRE(prices, 0, 1, fee);
 
        // Top-down DP approach
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solveTD(prices, 0, 1, dp, fee );
 
        // Bottom-up DP approach
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        // return solveBU(prices,  dp, fee);

        // Space-optimized DP approach
        vector<vector<int>> dp(2, vector<int>(2, 0));
        return solveSO(prices,  dp, fee);
    }
};
