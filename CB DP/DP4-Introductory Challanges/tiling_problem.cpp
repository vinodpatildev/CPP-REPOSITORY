#include<bits/stdc++.h>
using namespace std;
int waysTilingProblem(int lenWall ,vector<int> &dp){
    if(lenWall==0){return 1;}
    else if(lenWall<0){return 0;}
    if(dp[lenWall]!=-1){return dp[lenWall];}
    return dp[lenWall] = waysTilingProblem(lenWall-1,dp) + waysTilingProblem(lenWall-4,dp);
}
int SolveTilesProblem(int lenWall){
    vector<int> dp(lenWall+1,-1);
    return waysTilingProblem(lenWall,dp);
}
int main(){
    cout<<"Ans :"<<SolveTilesProblem(100);
    return 0;
}