//leetcode 494. Target Sum

class Solution {
public:
    // Recursive Solution
    int solve(vector<int>& nums, int target, int i) {
        if (i == nums.size())  return target == 0 ? 1 : 0;

        int plus = solve(nums, target - nums[i], i + 1);
        int minus = solve(nums, target + nums[i], i + 1);
        return plus + minus;
    }
    // Top-Down DP (Memoization)
    int solveTD(vector<int>& nums, int target, int i, map<pair<int, int>, int>& dp) {
        if (i == nums.size()) return target == 0 ? 1 : 0;
        if (dp.find({i, target}) != dp.end()) return dp[{i, target}];
        int plus = solveTD(nums, target - nums[i], i + 1, dp);
        int minus = solveTD(nums, target + nums[i], i + 1, dp);
        return dp[{i, target}] = plus + minus;
    }

    // Bottom-Up DP (Tabulation)
    int solveBU(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp; // {index, sum} -> number of ways
        dp[{nums.size(), 0}] = 1; // Base case: 1 way to make sum 0 with no elements

        int total = 0;
        for (auto num : nums) total += num;

        for (int i = nums.size() - 1; i >= 0; --i) {
            map<pair<int, int>, int> temp;
            for (int sum = -total; sum <= total; ++sum) {
                int plus = dp.find({i + 1, sum - nums[i]}) != dp.end() ? dp[{i + 1, sum - nums[i]}] : 0;
                int minus = dp.find({i + 1, sum + nums[i]}) != dp.end() ? dp[{i + 1, sum + nums[i]}] : 0;
                dp[{i, sum}] = plus + minus;
            }
        }
        return dp[{0, target}];
    }

        int findTargetSumWays(vector<int>& nums, int target) {
        // Recursive Approach
        // return solve(nums, target, 0);

        // Top-Down DP (Memoization)
        // map<pair<int, int>, int> dp; // {index, target} -> number of ways
        // return solveTD(nums, target, 0, dp);

        // Bottom-Up DP (Tabulation)
        return solveBU(nums, target);
    }
};
