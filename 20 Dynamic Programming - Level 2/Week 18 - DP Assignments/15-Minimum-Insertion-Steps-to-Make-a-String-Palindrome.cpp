//leetcode 1312. Minimum Insertion Steps to Make a String Palindrome

class Solution {
public:
    // Function to find the Longest Palindromic Subsequence (LPS) length using Tabulation
    int solveUsingTabSO(string a, string b) {
        // We use two arrays for space optimization
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        // Traverse the strings from the end towards the start
        for (int i = a.length() - 1; i >= 0; --i) {
            for (int j = b.length() - 1; j >= 0; --j) {
                int ans = 0;

                // If characters match
                if (a[i] == b[j]) {
                    ans = 1 + next[j + 1];
                } 
                // If characters don't match
                else {
                    ans = 0 + max(curr[j + 1], next[j]);
                }

                // Update the current dp array
                curr[j] = ans;
            }
            //. Shift the current row to the next row for the next iteration
            next = curr;
        }

        return next[0];
    }

    // Function to find the length of the longest palindromic subsequence
    int longestPalindromeSubseq(string& s) {
        string first = s;
        

        // Reverse the string to find LPS
        reverse(s.begin(), s.end());
        string second = s;
        return solveUsingTabSO(first, second);
    }

    // Function to calculate the minimum number of insertions to make the string a palindrome
    int minInsertions(string s) {
        // Length of the part that is already palindromic
        int LPS_len = longestPalindromeSubseq(s);

        // Insertions required to make the string a palindrome
        int insertionsToDo = s.size() - LPS_len;

        return insertionsToDo;
    }
};
