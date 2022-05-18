// An Array is give we have to sort it in way 
// such that elements at even postions are 
// always greater thant thier neighbors

// This can we done in 2 ways: 
// 1] sort the array first and then swap consecutive pairs elements
// 2] sort it in way such that elements at even position will alway remain greater than neighbors.

#include <bits/stdc++.h>
using namespace std;
void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void sortInWave(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i += 2){
        if(i>0 && arr[i-1]>arr[i]){
            swap(&arr[i-1],&arr[i]);
        }
        if(i<n-1 && arr[i+1]>arr[i]){
            swap(&arr[i+1],&arr[i]);
        }
    }
}

print_arr(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {10, 90, 49, 2, 1, 5, 23};
    cout<<"Array Before :";
    print_arr(arr);

    sortInWave(arr);

    cout<<"Array After  :";
    print_arr(arr);
    return 0;
}