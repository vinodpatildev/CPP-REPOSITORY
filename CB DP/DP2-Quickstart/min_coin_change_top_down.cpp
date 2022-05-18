#include<bits/stdc++.h>
using namespace std;
int min_coin_change(int num,vector<int> &coins, vector<int> &dp){
    if(num==0){return 0;}
    if(dp[num]!=-1){return dp[num];}
    int minCoinChange = INT_MAX;
    for(int i=0; i<coins.size();i++){
        if(num<coins[i]){break;}
        minCoinChange = min(minCoinChange, min_coin_change(num-coins[i],coins,dp));
    }
    return dp[num]=minCoinChange+1;
}
int main(){
    int n = 10;
    vector<int> dp(n+1,-1);
    vector<int> coins = {1,7,10};
    cout<<"Ans : "<<min_coin_change(n,coins,dp)<<endl;
    return 0;
}