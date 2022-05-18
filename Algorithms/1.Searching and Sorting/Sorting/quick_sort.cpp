#include <bits/stdc++.h>
using namespace std;
void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
int partition(int arr[],int leftIndex,int rightIndex){
    int pivot = arr[rightIndex];
    int j=leftIndex-1;
    for(int i = leftIndex; i<rightIndex; i++){
        if(arr[i]<=pivot){
            swap(&arr[i],&arr[++j]);
        }
    }
    swap(&arr[++j],&arr[rightIndex]);
    cout<<"pivot :"<<j<<endl;
    return j;
}
    
void quick_sort(int arr[],int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
}
void print_arr(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {13,19,9,5,12,8,7,4,11,2,6,21};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting : ";
    print_arr(arr,arr_size);

    quick_sort(arr,0,arr_size-1);

    cout<<"After  Sorting : ";
    print_arr(arr,arr_size);
     
    return 0;
}