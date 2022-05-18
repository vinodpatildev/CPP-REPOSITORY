#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> &arr){
    vector<int> dp(arr.size(),0);
    dp[0] = arr[0]>=0 ? arr[0] : 0;
    int maxSubSum = arr[0];
    for(int i=1; i<arr.size(); i++){
        dp[i] = dp[i-1]+arr[i]>0?dp[i-1]+arr[i]:0;
        maxSubSum = max(maxSubSum,dp[i]);
    }
    return maxSubSum;
}
int main(){
    vector<int> arr = {-3,2,5,-1,6,3,-2,7,-5,2};
    cout<<"Ans :"<<maxSumSubarray(arr);
    return 0;
} 