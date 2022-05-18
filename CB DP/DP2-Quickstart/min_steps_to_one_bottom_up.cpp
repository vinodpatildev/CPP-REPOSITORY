#include<bits/stdc++.h>
using namespace std;
int min_steps_to_one(int num,vector<int> &dp){
    dp[1]=0;
    int ans=0,op1,op2,op3;
    for(int i=2; i<=num; i++){
        op1 = op2 = op3 = INT_MAX;
        if(i%3==0){op1=dp[i/3];}
        if(i%2==0){op2=dp[i/2];}
        op3=dp[i-1];
        dp[i]  = min(min(op1,op2),op3)+1;
    }
    return dp[num];
}
int main(){
    int n = 6;
    vector<int> dp(n+1,-1);
    cout<<"Ans : "<<min_steps_to_one(n,dp)<<endl;
    return 0;
}