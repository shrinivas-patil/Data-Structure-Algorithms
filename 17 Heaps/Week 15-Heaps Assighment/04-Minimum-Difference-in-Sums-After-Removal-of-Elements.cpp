class Solution {
public:
#define ll long long
void print(vector<ll>& v) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        vector<ll>prefix(nums.size(), -1), suffix(nums.size(), -1); 
        // prefix[i] = sum of first n elements from the left side.
        // suffix[i] = sum of first n elements from the right side.

        ll sum = 0; // Minimum n elements sum
        priority_queue<ll> pq; // max heap

        // Calculate prefix sums for the first n elements
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            pq.push(nums[i]);

            // Pop out max elements to maintain the n smallest
            if (pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == n) {
                prefix[i] = sum;
            }
        }

        sum = 0; // Maximum n elements sum
        priority_queue<ll, vector<ll>, greater<ll>> pq2; // min heap

        // Calculate suffix sums for the last n elements
        for (int i = nums.size() - 1; i >= 0; --i) {
            sum += nums[i];
            pq2.push(nums[i]);

            // Pop out min elements to maintain the n largest
            if (pq2.size() > n) {
                sum -= pq2.top();
                pq2.pop();
            }

            if (pq2.size() == n) {
                suffix[i] = sum;
            }
        }
        ll ans = LLONG_MAX;

        // Compute the minimum difference between prefix and suffix sums
        for (int i = n - 1; i < 2 * n; ++i) {
            ans = min(ans, prefix[i] - suffix[i + 1]);
        }

        return ans;
    }
};
