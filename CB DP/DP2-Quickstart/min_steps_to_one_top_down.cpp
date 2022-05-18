#include<bits/stdc++.h>
using namespace std;
int min_steps_to_one(int num,vector<int> &dp){
    if(num==1){return 0;}
    if(dp[num]!=-1){return dp[num];}
    int ans = INT_MAX;
    if(num%3==0){ans = min(ans,min_steps_to_one(num/3,dp));}
    if(num%2==0){ans = min(ans,min_steps_to_one(num/2,dp));}
    ans = min(ans,min_steps_to_one(num-1,dp));

    return dp[num]=ans+1;
}
int main(){
    int n = 10;
    vector<int> dp(n+1,-1);
    dp[1]=0;
    cout<<"Ans : "<<min_steps_to_one(n,dp)<<endl;
    return 0;
}