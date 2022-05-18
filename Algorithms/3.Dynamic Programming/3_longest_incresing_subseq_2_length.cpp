#include<bits/stdc++.h>
using namespace std;
int largest_increasing_subsequence(int *arr, int arr_size){
    int lis[arr_size];
    lis[0] = 1;
    cout<<endl;
    for(int i=1; i<arr_size; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i] && lis[j]+1>lis[i]){
                lis[i] = lis[j]+1;
            }
        }
        for(int j=0; j<=i; j++){
            cout<<lis[j]<<" ";
        }cout<<endl;
    }
    return *max_element(lis,lis+arr_size);
}
int main()
{   
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 ,80};
    // int arr[] = {1,2,3,4,5,44,6,7,8,11,9,10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Largest Increasing Sub-Sequence :"<<largest_increasing_subsequence(arr,arr_size)<<endl;
    return 0;
}