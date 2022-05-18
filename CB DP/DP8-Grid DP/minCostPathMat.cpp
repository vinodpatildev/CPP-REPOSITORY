#include<bits/stdc++.h>
using namespace std;
int minCostPath(vector<vector<int>> &mat){
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row,vector<int>(col,-1));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 && j==0){dp[i][j] = mat[i][j];}
            else if(i==0){dp[i][j] = dp[i][j-1] + mat[i][j];}
            else if(j==0){dp[i][j] = dp[i-1][j] + mat[i][j];}
            else{dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + mat[i][j];}
        }
    }
    cout<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    cout<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    return dp[row-1][col-1];
}
int main(){
    vector<vector<int>> mat ={ vector<int> { 1, 2, 3 },
                       vector<int> { 4, 8, 2 },
                       vector<int> { 1, 5, 3 } } ;
    cout<<"Ans :"<<minCostPath(mat)<<endl;
    return 0;
}