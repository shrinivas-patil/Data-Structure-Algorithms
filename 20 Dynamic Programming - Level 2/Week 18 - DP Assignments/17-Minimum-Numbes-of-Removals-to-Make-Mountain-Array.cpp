//leetcode 1671. Minimum Number of Removals to Make Mountain Array


class Solution {
public:
    // Function to find the LIS or LDS length and populate the respective array
    int solveOptimal(vector<int>& arr, vector<int>& lis) {
        if (arr.size() == 0)
            return 0;

        vector<int> ans; // To maintain the increasing subsequence
        lis.push_back(1); // First element will always have LIS of 1
        ans.push_back(arr[0]); // Add the first element to 'ans'

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > ans.back()) {
                // Include current element in LIS
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
            } else {
                // Overwrite the just-bigger element in 'ans'
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
                lis.push_back(index + 1);
            }
        }

        return ans.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis, lds;

        // Find LIS for each element
        solveOptimal(nums, lis);

        // Reverse the array to calculate LDS
        reverse(nums.begin(), nums.end());
        solveOptimal(nums, lds);

        // Reverse LDS to align it with the original array
        reverse(lds.begin(), lds.end());

        // Main logic to find the largest mountain
        int largestMountain = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (lis[i] == 1 || lds[i] == 1) // Single peak element cannot form a mountain
                continue;
            largestMountain = max(largestMountain, lis[i] + lds[i] - 1);
            
        }

        // Calculate the minimum removals to form the largest mountain
        int minRemovals = nums.size() - largestMountain;

        return minRemovals;
    }
};
