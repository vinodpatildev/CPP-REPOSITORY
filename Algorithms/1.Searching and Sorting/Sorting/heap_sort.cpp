#include <bits/stdc++.h>
using namespace std;
void swap(int *p,int *q){
    int temp = *p;
    (*p) = (*q);
    (*q) = temp;
}
void Heapify(int *arr,int size, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<size && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<size && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        Heapify(arr,size,largest);
    }    
}
void heap_sort(int arr[],int size){
    for(int i = size/2 -1; i>=0; i--){
        Heapify(arr,size,i);
    }
    for(int i = size-1; i>0; i--){
        swap(&arr[i],&arr[0]);
        Heapify(arr,i,0);
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
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting : ";
    print_arr(arr,arr_size);

    heap_sort(arr,arr_size);

    cout<<"After  Sorting : ";
    print_arr(arr,arr_size);
     
    return 0;
}