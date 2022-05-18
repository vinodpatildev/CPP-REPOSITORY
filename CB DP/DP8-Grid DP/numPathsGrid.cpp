#include<bits/stdc++.h>
using namespace std;
int numPathGridRat(vector<vector<int>> &mat){
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row,vector<int>(col,-1));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 && j==0){dp[i][j] = 1;}
            else if(i==0){dp[i][j] = 1;}
            else if(j==0){dp[i][j] = 1;}
            else{dp[i][j] = dp[i-1][j]+dp[i][j-1]/*+dp[i-1][j-1]*/;}
        }
    }
    // cout<<endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<mat[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    // cout<<endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;

    //If cells are not blocked
    // ans = ((row-1) + (col -1))!/(row-1)!(col-1)!
    return dp[row-1][col-1];
}
int numPathGridElephant(vector<vector<int>> &mat){
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<int>> dp(row,vector<int>(col,0));
    vector<vector<int>> sumUp(row,vector<int>(col,0));
    vector<vector<int>> sumLeft(row,vector<int>(col,0));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
                sumUp[i][j] = 1;
                sumLeft[i][j] = 1;
            }
            else if(i==0){
                dp[i][j] = sumLeft[i][j-1];
                sumUp[i][j] = dp[i][j];
                sumLeft[i][j] = sumLeft[i][j-1]+dp[i][j];
            }
            else if(j==0){
                dp[i][j] = sumUp[i-1][j];
                sumUp[i][j] = sumUp[i-1][j]+dp[i][j];
                sumLeft[i][j] = dp[i][j];
            }
            else{
                dp[i][j] = sumUp[i-1][j]+sumLeft[i][j-1];
                sumUp[i][j] = sumUp[i-1][j]+dp[i][j];
                sumLeft[i][j] = sumLeft[i][j-1]+dp[i][j];
            }
        }
    }
    cout<<"-------------------------"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<sumUp[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    cout<<"-------------------------"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<sumLeft[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    cout<<"-------------------------"<<endl;

    return dp[row-1][col-1];
}
int main(){
    vector<vector<int>> mat ={ vector<int> { 1, 2, 3 },
                       vector<int> { 4, 8, 2 },
                       vector<int> { 1, 5, 3 } } ;
    cout<<"Ans :"<<numPathGridElephant(mat)<<endl;
    return 0;
}