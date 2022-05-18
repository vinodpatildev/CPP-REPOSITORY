#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int l1,int r1, int l2, int r2){
    int arr_size1 = r1 - l1 + 1;
    int arr_size2 = r2 - l2 + 1;

    int *arr1 = new int[arr_size1];
    int *arr2 = new int[arr_size2];
    
    for(int i=0;i<arr_size1;i++){
        arr1[i] = arr[l1+i];
    }
    for(int j=0;j<arr_size2;j++){
        arr2[j] = arr[l2+j];
    }
    int i=0,j=0;
    int k = l1;
    while(i<arr_size1&&j<arr_size2){
        if(arr1[i]<=arr2[j]){
            arr[k++] = arr1[i++];
            // i++;
        }else{
            arr[k++] = arr2[j++];
            // j++;
        }
        // k++;
    }
    while(i<arr_size1){
        arr[k++] = arr1[i++];
        // k++;
        // i++;
    }
    while(j<arr_size2){
        arr[k++] = arr2[j++];
        // k++;
        // j++;
    }
    return;
}
void merge_sort(int arr[],int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,mid+1,r);
    }
}
void print_arr(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[10] = {5,33,7,15,0,13,81,9,1,50};
    int arr1[2] = {2,1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting : ";
    print_arr(arr,arr_size);

    merge_sort(arr,0,arr_size-1);

    cout<<"After  Sorting : ";
    print_arr(arr,arr_size);
     
    return 0;
}