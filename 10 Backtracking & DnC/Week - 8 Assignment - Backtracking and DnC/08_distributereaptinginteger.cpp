//leetcode 1655 distribute reapiting integers
class Solution {
public:
    bool canDistributehelper(vector<int> &counts,vector<int> &quantity,int ithcustomer){
        //base
        if(ithcustomer==quantity.size()){
            return true;
        }
        for(int i=0;i<counts.size();i++){
            if(counts[i]>=quantity[ithcustomer]){
                counts[i]-=quantity[ithcustomer];
                if(canDistributehelper(counts,quantity,ithcustomer+1)){
                return true;
                }
                counts[i]+=quantity[ithcustomer];//backtraking
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countmap;
        for(auto num:nums){
            countmap[num]++;
        }
        vector<int>counts;
        for(auto it:countmap){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        return canDistributehelper(counts,quantity,0);
    }
};