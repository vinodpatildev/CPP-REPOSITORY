#include<bits/stdc++.h>
using namespace std;
int calMatMul(int i, int j, vector<int> &mat,vector<vector<int>> &dp){
    if(i==j){
        return dp[i][j] = 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int minCal = INT_MAX;
    for(int k=i; k<j; k++){
        minCal = min(minCal,calMatMul(i,k,mat,dp) + calMatMul(k+1,j,mat,dp) + mat[i-1]*mat[k]*mat[j]);
    }
    return dp[i][j] = minCal;
}
int minMatMul(vector<int> &mat){
    int size = mat.size();
    vector<vector<int>> dp(size,vector<int>(size,-1));
    return calMatMul(1,size-1,mat,dp);
}
int main(){
    vector<int> mat = {10, 20, 30, 40, 30} ;
    cout<<"Ans :"<<minMatMul(mat);
    return 0;
} 