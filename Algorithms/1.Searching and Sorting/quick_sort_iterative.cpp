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
    return j;
}
void quick_sort_iterative(int arr[],int l, int r){
    int stack[r-l+1];
    
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;

    while(top>=0){
        r = stack[top--];
        l = stack[top--];

        int p = partition(arr,l,r);

        if(p-1>l){
            stack[++top] = l;
            stack[++top] = p-1;
        }
        if(p+1<r){
            stack[++top] = p+1;
            stack[++top] = r;
        }
    }
}
void print_arr(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[20] = {5,33,7,15,0,13,81,9,1,50,5,33,7,15,0,13,81,9,1,50};
    int arr1[2] = {2,1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting : ";
    print_arr(arr,arr_size);

    quick_sort_iterative(arr,0,arr_size-1);

    cout<<"After  Sorting : ";
    print_arr(arr,arr_size);
     
    return 0;
}