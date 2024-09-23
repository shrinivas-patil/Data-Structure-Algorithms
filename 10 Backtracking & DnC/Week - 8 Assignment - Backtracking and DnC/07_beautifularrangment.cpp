//leetcode 526 beautiful arranmgment
class Solution {
public:
    void countArrangementhelper(vector<int> &v,int &n,int &ans,int currNum){
        //basic
        if(currNum == n+1){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(v[i]==0 && (currNum%i==0 || i%currNum==0)){
                v[i]=currNum;
                countArrangementhelper(v,n,ans,currNum+1);
                v[i]=0;//backtraking
            }
        }
    }
    int countArrangement(int n) {
       vector<int>v(n+1);
       int ans =0;
       countArrangementhelper(v,n,ans,1);
       return ans; 
    }
};