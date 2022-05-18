#include <bits/stdc++.h>
using namespace std;
void swap(int arr[], int first_index, int second_index){
    int temp = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp;
}
void bubble_sort(int arr[],int size){
    int rightIndex = size - 1;
    
    while(rightIndex){        
        for(int i = 0; i < rightIndex; i++){
            if(arr[i] > arr[i+1]){
                swap(arr,i,i+1);
            }
        }
        rightIndex--;
    }
}
print_arr(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[10] = {5,33,7,55,23,77,1,90,34,19};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting : ";
    print_arr(arr,arr_size);

    bubble_sort(arr,arr_size);

    cout<<"After  Sorting : ";
    print_arr(arr,arr_size);
     
    return 0;
}