#include<bits/stdc++.h>
using namespace std;
void printArray(int *arr,int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sortK(int *arr,int n,int k){
    int size = (k==n)?k:k+1;
    priority_queue<int,vector<int>, greater<int>> pq(arr,arr+size);
    int index = 0;
    for(int i=k+1; i<n; i++){
        arr[index++] = pq.top();pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        arr[index++] = pq.top();pq.pop();
    }
}
int main()
{
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted array" << endl;
    printArray(arr, n);

    return 0;
}




