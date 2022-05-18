#include<bits/stdc++.h>
using namespace std;
int maxProfitWines(vector<int> &wines,vector<vector<int>> &dp,int left,int right,int year){
    if(dp[left][right]!=-1){return dp[left][right];}
    if(left==right){return dp[left][right]=year*wines[left];}
    return dp[left][right]=max(year*wines[left] + maxProfitWines(wines,dp,left+1,right,year+1), year*wines[right] + maxProfitWines(wines,dp,left,right-1,year+1));
}
int maxProfitWines(vector<int> &wines){
    vector<vector<int>> dp(wines.size(),vector<int>(wines.size(),-1));
    return maxProfitWines(wines,dp,0,wines.size()-1,1);
}
int main(){
    vector<int> wines = {2,3,5,1,4};
    
    cout<<"Ans : "<<maxProfitWines(wines)<<endl;
    return 0;
}