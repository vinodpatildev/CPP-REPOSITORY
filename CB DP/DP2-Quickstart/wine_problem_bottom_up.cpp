#include<bits/stdc++.h>
using namespace std;
int maxProfitWines(vector<int> &wines){
    int size = wines.size();
    vector<vector<int>> dp(wines.size(),vector<int>(wines.size(),-1));
    for(int left=size-1; left>=0; left-- ){
        for(int right=left; right<size; right++){
            if(left>right){continue;}
            dp[left][right] = left==right?wines[left]*(size):max(wines[left]*(size-right+left) + dp[left+1][right],wines[right]*(size-right+left) + dp[left][right-1]);
        }
    }
    return dp[0][size-1];
}
int main(){
    vector<int> wines = {2,3,5,1,4};
    cout<<"Ans : "<<maxProfitWines(wines)<<endl;
    return 0;
}