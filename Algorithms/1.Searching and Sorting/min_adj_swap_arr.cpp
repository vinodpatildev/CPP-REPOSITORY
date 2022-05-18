#include<bits/stdc++.h>
using namespace std;
//Driver Code
int solve(int *arr,int size){
    int min = 0;
    int max = size-1;
    for(int i=0; i<size; i++){
        if(arr[i]<arr[min]){
            min = i;
        }
        if(arr[i]>arr[max]){
            max = i;
        }
    }
    if(max < min){
        return max + (size-min-1);
    }
    return max+(size-min-2);
}
int main()
{
    int arr[] = { 5, 6, 1, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr, n)<<endl;
    return 0;
}