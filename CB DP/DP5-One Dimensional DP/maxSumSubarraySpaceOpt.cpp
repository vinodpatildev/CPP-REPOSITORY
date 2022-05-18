#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> &arr){
    int prevSum = arr[0]>=0 ? arr[0] : 0;
    int maxSubSum = arr[0];
    for(int i=1; i<arr.size(); i++){
        prevSum = prevSum+arr[i]>0?prevSum+arr[i]:0;
        maxSubSum = max(maxSubSum,prevSum);
    }
    return maxSubSum;
}
int main(){
    vector<int> arr = {-3,2,5,-1,6,3,-2,7,-5,2};
    cout<<"Ans :"<<maxSumSubarray(arr);
    return 0;
} 