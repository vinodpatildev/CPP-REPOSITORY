#include <bits/stdc++.h>
#include<climits>
#include<cstdlib>
using namespace std;
void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void print_arr(vector<int> &arr, int left = 0, int right = 0){
    if(!right){
        right = arr.size()-1;
    }
    for(int i=left; i<=right; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(vector<int> &arr,int left,int right){
    int pivot = left + rand()%(right-left+1);
    // cout<<endl;print_arr(arr,left,right);
    // cout<<"pivote :"<< pivot <<"\n"; 
    swap(&arr[pivot],&arr[right]);
    int k = left-1;
    for(int i=left; i<=right; i++){
        if(arr[i]<=arr[right]){
            swap(&arr[i],&arr[++k]);
        }
    }
    // cout<<"       :"<< k <<"\n"; 
    // print_arr(arr,left,right);
    return k;
}
int quickSelect(vector<int> &arr,int left, int right, int k){
    if(left <= right){
        int p = partition(arr,left,right);
        if(p == k-1){
            return arr[p];
        }
        if(p > k-1){
            right = p-1;
            return quickSelect(arr,left,right,k);
        }else{
            left = p+1;
            return quickSelect(arr,left,right,k);
        }
    }
    return -1;
}


int main(){
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26, 22, 25, 1, 17, 0,2};
    cout<<"Array Before :";
    print_arr(arr);
    int K;
    cout<<"Enter value of K :";
    cin>>K;
    cout<<quickSelect(arr,0,arr.size()-1,K)<<endl;

    cout<<"Array After  :";
    print_arr(arr);
    return 0;
}