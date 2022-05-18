#include<bits/stdc++.h>
using namespace std;
int minEggDrop(int n, int k){
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(i==1){dp[i][j]=j;}
            else if(j==1){dp[i][j]=1;}
            else{
                dp[i][j] = INT_MAX;
                for(int k=1; k<=j; k++){
                    dp[i][j] = min(dp[i][j],max(dp[i][j-k],dp[i-1][k-1])+1);
                }
            }
        }
    }
    cout<<endl;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return dp[k][n];
}
int main(){
    int n=5,k=2;    
    cout<<"Ans :"<<minEggDrop(n,k)<<endl;
    return 0;
}