//leetcode 801. Minimum Swaps To Make Sequences Increasing

class Solution {
public:
    // Recursive function
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2) {
        if (i == nums1.size()) {
            return 0; // Base case: End of the arrays
        }

        int swap = INT_MAX, noSwap = INT_MAX;
        // Swap condition
        if (prev1 < nums2[i] && prev2 < nums1[i]) {
            swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i]);
        }

        // No swap condition
        if (prev1 < nums1[i] && prev2 < nums2[i]) {
            noSwap = solve(nums1, nums2, i + 1, nums1[i], nums2[i]);
        }
        return min(swap, noSwap);
    }
        // Recursive function with memoization (Top-Down DP)
    int solveTD(vector<int>& nums1, vector<int>& nums2, int i, int p1, int p2, vector<vector<int>>& dp, int isSwap) {
        if (i == nums1.size()) {
            return 0; // Base case: Reached the end of arrays
        }
        if (dp[i][isSwap] != -1) return dp[i][isSwap]; // Return cached result
        int swap = INT_MAX, noSwap = INT_MAX;
        // Swap condition
        if (p1 < nums2[i] && p2 < nums1[i]) {
            swap = 1 + solveTD(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
        }
        // No swap condition
        if (p1 < nums1[i] && p2 < nums2[i]) {
            noSwap = solveTD(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
        }
        return dp[i][isSwap] = min(swap, noSwap);
    }

    // Iterative Bottom-Up DP approach
    int solveBU(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0)); // Bottom-up DP table

        for (int i = nums1.size()- 1; i >= 1; --i) {
            for (int j = 1; j >= 0; --j) {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];
                if(j){
                    swap(prev1, prev2);
                }

                int swap = INT_MAX, noSwap = INT_MAX;
                // Swap condition
                if(prev1 < nums2[i] && prev2 < nums1[i]) {
                    swap = 1 + dp[i + 1][1];
                }

                // No swap condition
                if (prev1 < nums1[i] && prev2 < nums2[i]) 
                    noSwap = dp[i + 1][0];
                dp[i][j] = min(swap, noSwap);
            }
        }
        return dp[1][0];
    }

    // Main function
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solve(nums1, nums2, 0, -1, -1);

        // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1)); // Memoization table
        // return solveTD(nums1, nums2, 0, -1, -1, dp, 0);

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveBU(nums1, nums2);
    }
    
};

