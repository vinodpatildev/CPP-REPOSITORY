#include<bits/stdc++.h>
using namespace std;
int minMatMul(vector<int> &mat){
    int size = mat.size(),i,j,l,k;
    vector<vector<int>> dp(size,vector<int>(size,INT_MAX));
    for(l=1; l<size; l++){
        for(i=1; i<size+1-l; i++){
            j=i+l-1;
            if(i==j){dp[i][j] = 0;}
            else{
                for(k=i; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+mat[i-1]*mat[k]*mat[j]);
                }
            }
        }
    }
    cout<<endl;
    for(i=0;i<size; i++){
        for(j=0; j<size; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return dp[1][size-1];
}
int main(){
    vector<int> mat = {40, 20, 30, 10, 30} ;
    cout<<"Ans :"<<minMatMul(mat);
    return 0;
} 