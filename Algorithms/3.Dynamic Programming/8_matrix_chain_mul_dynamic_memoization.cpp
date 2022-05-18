#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int *mat,vector<vector<int>> &dp, int i, int j){
    if(j==i){return 0;}
    if(dp[i][j] != -1){return dp[i][j];}
    dp[i][j]=INT_MAX;
    for(int k=i; k<j; k++){
        dp[i][j] = min(dp[i][j],MatrixChainOrder(mat,dp,i,k) + MatrixChainOrder(mat,dp,k+1,j) + mat[i-1]*mat[k]*mat[j]);
    }
    return dp[i][j];
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> dp(100,vector<int>(100,-1));
    cout << "Minimum number of multiplications is :"<< MatrixChainOrder(arr,dp, 1, n - 1);
}