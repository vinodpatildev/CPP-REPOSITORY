#include<bits/stdc++.h>
using namespace std;
int c=0;
int solve(int i, int j,vector<int> &choco,vector<int> &candies,vector<vector<int>> &dp){
    c++;
    int temp;
    if(i==choco.size()){return 0;}
    else if(j==candies.size()){return INT_MAX;}
    int op1,op2;
    op1 = solve(i+1,j+1,choco,candies,dp);
    op2 = solve(i,j+1,choco,candies,dp);
    return op1==INT_MAX&&op2==INT_MAX? INT_MAX :min(op1+abs(choco[i]-candies[j]),op2);
}
int minValentine(vector<int> &choco,vector<int> &candies){
    int m=choco.size(),n=candies.size();
    sort(choco.begin(),choco.end());
    sort(candies.begin(),candies.end());
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(0,0,choco,candies,dp);
    // cout<<endl;
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    // return dp[m-1][n-1];
}
int main(){
    int m = 2;
    int n = 5;
    vector<int> chocolates = {4, 5};
    vector<int> candies = {6,4,3,2,1};
    
    cout<<"Ans :"<<minValentine(chocolates,candies)<<endl;
    cout<<"Total Function calls :"<<c<<endl;
    return 0;
}