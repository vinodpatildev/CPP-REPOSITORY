#include<bits/stdc++.h>
using namespace std;

int waysToReachLadder(int num,int k){
    vector<int> dp(num+1,0);
    for(int i=1; i<=num; i++){
        for(int j=1;j<=k;j++){
            if(i-j==0){dp[i]+=1;continue;}
            else if(i-j<0){continue;}
            dp[i]+=dp[i-j];
        }
    }
    return dp[num];
}
int main(){
    cout<<"Ans :"<<waysToReachLadder(10,3);
    return 0;
} 