#include<bits/stdc++.h>
using namespace std;
int min_coin_change_bottom_up(int change,vector<int> &coins, vector<int> &dp){
    dp[0]=0;
    for(int i=1; i<=change; i++){
        for(int j=0; j<coins.size(); j++){if(coins[j]>i){break;}dp[i] = min(dp[i], dp[i-coins[j]]+1);}
    }
    return dp[change];
}
int main(){
    int n = 15;
    vector<int> dp(n+1,INT_MAX);
    vector<int> coins = {1,7,10};
    cout<<"Ans : "<<min_coin_change_bottom_up(n,coins,dp)<<endl;
    return 0;
}