//leetcode 53 maximum subarray
class Solution {
public:
    int maxsumarrayhelper(vector<int> &v,int start,int end) {
        if(start==end)return v[start];
        int maxleftboardsum = INT_MIN, maxrightboardsum = INT_MIN;
        int mid = start + ((end-start)>>1);

        int maxleftsum = maxsumarrayhelper(v,start,mid);
        int maxrightsum = maxsumarrayhelper(v,mid+1,end);

        //max cross board sum
        int leftboardsum = 0,rightboardsum = 0;
        for(int i = mid;i >= start;i--){
            leftboardsum += v[i];
            if(leftboardsum>maxleftboardsum) maxleftboardsum=leftboardsum;
        }
        for(int i = mid+1;i <= end;i++){
            rightboardsum += v[i];
            if(rightboardsum>maxrightboardsum) maxrightboardsum=rightboardsum;
        }
        int crossboardsum = maxleftboardsum + maxrightboardsum;
        return max(maxleftsum,max(maxrightsum,crossboardsum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxsumarrayhelper(nums,0,nums.size()-1);
    }
};