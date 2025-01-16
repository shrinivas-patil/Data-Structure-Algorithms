//leetcode 123. Best Time to Buy and Sell Stock III

class Solution {
public:
    // Recursive Solution
    int solveRE(vector<int>& prices, int i, int buy, int limit) {
        if (i >= prices.size() || limit == 0) return 0;

        int profit = 0;

        if (buy) {
            int buyItProfit = -prices[i] + solveRE(prices, i + 1, 0, limit);
            int skipProfit = solveRE(prices, i + 1, 1, limit);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solveRE(prices, i + 1, 1, limit - 1);
            int skipProfit = solveRE(prices, i + 1, 0, limit);
            profit = max(sellItProfit, skipProfit);
        }

        return profit;
    }

    // Top-Down Dynamic Programming (Memoization)
    int solveTD(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || limit == 0) return 0;

        if (dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;

        if (buy) {
            int buyItProfit = -prices[i] + solveTD(prices, i + 1, 0, limit, dp);
            int skipProfit = solveTD(prices, i + 1, 1, limit, dp);
            profit = max(buyItProfit, skipProfit);
        } else {
            int sellItProfit = prices[i] + solveTD(prices, i + 1, 1, limit - 1, dp);
            int skipProfit = solveTD(prices, i + 1, 0, limit, dp);
            profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy][limit] = profit;
        return profit;
    }

    // Bottom-Up Dynamic Programming (Tabulation)
    int solveBU(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp) {
        int n = prices.size();
        

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int limit = 1; limit <= 2; ++limit) {
                    int profit = 0;

                    if (buy) {
                        int buyItProfit = -prices[i] + dp[i + 1][0][limit];
                        int skipProfit = dp[i + 1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    } else {
                        int sellItProfit = prices[i] + dp[i + 1][1][limit - 1];
                        int skipProfit = dp[i + 1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }

                    dp[i][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

    // Space Optimized Dynamic Programming
    int solveSO(vector<int>& prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp) {
        int n = prices.size();

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int limit = 1; limit <3; ++limit) {
                    int profit = 0;

                    if (buy) {
                        int buyItProfit = -prices[i] + dp[1][0][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    } else {
                        int sellItProfit = prices[i] + dp[1][1][limit - 1];
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }

                    dp[0][buy][limit] = profit;
                }
            }
            dp[1] = dp[0];
        }

        return dp[0][1][2];
    }

    // Main Function to Calculate Max Profit
    int maxProfit(vector<int>& prices) {
        // Recursive
        // return solveRE(prices, 0, 1, 2);

        // Top-Down DP
        // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // return solveTD(prices, 0, 1, 2, dp);

        // Bottom-Up DP
        // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return solveBU(prices, 0 ,1, 2, dp);

        // Space Optimized DP
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));
        return solveSO(prices, 0, 1, 2, dp);
    }
};
