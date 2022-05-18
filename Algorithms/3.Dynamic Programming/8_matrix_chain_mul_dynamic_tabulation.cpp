#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int *mat,int size){
    vector<vector<int>> dp(size,vector<int>(size,-1));
    int i,j,k,L,q;
    for(i=1; i<size; i++){
        dp[i][i]=0;
    }
    for(L=2;L<size;L++){
        for(i=1; i<size-L+1; i++){
            j = i+L-1;
            dp[i][j] = INT_MAX;
            for(k=i; k<=j-1; k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + mat[i-1]*mat[k]*mat[j]);
            }
        }
    }
    return dp[1][size-1];
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is :"<< MatrixChainOrder(arr,n);
}

// MatrixChainOrder(mat,dp,i,k) + MatrixChainOrder(mat,dp,k+1,j) + mat[i-1]*mat[k]*mat[j]