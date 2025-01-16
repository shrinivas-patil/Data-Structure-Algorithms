//leetcode 97. Interleaving String

class Solution {
public:
    // Recursive Solution
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) return true; // Base case
        
        bool flag = false;

        // Check if we can take a character from s1
        if (i < s1.size() && s1[i] == s3[k]) {
            flag = flag || solve(s1, s2, s3, i + 1, j, k + 1);
        }

        // Check if we can take a character from s2
        if (j < s2.size() && s2[j] == s3[k]) {
            flag = flag || solve(s1, s2, s3, i, j + 1, k + 1);
        }

        return flag;
    }

    // Top-Down (Memoized) Solution
    bool solveTD(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (i == s1.size() && j == s2.size() && k == s3.size()) return true; // Base case

        if (dp[i][j][k] != -1) return dp[i][j][k]; // Return memoized result

        bool flag = false;

        // Check if we can take a character from s1
        if (i < s1.size() && s1[i] == s3[k]) {
            flag = flag || solveTD(s1, s2, s3, i + 1, j, k + 1, dp);
        }

        // Check if we can take a character from s2
        if (j < s2.size() && s2[j] == s3[k]) {
            flag = flag || solveTD(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        return dp[i][j][k] = flag; // Store result
    }

    // Bottom-Up (Iterative) Solution
    bool solveBU(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if (n1 + n2 != n3) return false; // Early check for mismatched lengths

        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));
        dp[n1][n2][n3] = 1; // Base case

        for (int i = n1; i >= 0; --i) {
            for (int j = n2; j >= 0; --j) {
                for (int k = n3; k >= 0; --k) {
                    if (i == n1 && j == n2 && k == n3) continue; // Skip base case

                    bool flag = false;

                    // Check if we can take a character from s1
                    if (i < n1 && k < n3 && s1[i] == s3[k]) {
                        flag = flag || dp[i + 1][j][k + 1];
                    }

                    // Check if we can take a character from s2
                    if (j < n2 && k < n3 && s2[j] == s3[k]) {
                        flag = flag || dp[i][j + 1][k + 1];
                    }

                    dp[i][j][k] = flag;
                }
            }
        }

        return dp[0][0][0]; // Final result
    }

    bool isInterleave(string s1, string s2, string s3) {
        // Recursive Solution
        // return solve(s1, s2, s3, 0, 0, 0);

        // Top-Down (Memoized) Solution
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
        // return solveTD(s1, s2, s3, 0, 0, 0, dp);

        // Bottom-Up (Iterative) Solution
        return solveBU(s1, s2, s3);
    }
};
