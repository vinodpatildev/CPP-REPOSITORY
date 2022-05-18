#include<bits/stdc++.h>
using namespace std;
void printClosest(int *arr, int size, int target){
    int l,r;
    int left = 0;
    int right = size-1;
    int diff = INT_MAX;
    while(left<right){
        if(abs(arr[left]+arr[right]-target) < diff){
            diff = abs(arr[left]+arr[right]-target);
            l = left;
            r = right;
        }
        if(arr[left]+arr[right] > target){
            right--;
        }else{
            left++;
        }
    }
    cout<<arr[l]<<" "<<arr[r]<<endl;
}
int main()
{
    int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54;
    int n = sizeof(arr)/sizeof(arr[0]);
    printClosest(arr, n, x);
    return 0;
}