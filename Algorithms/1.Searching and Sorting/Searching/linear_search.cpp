#include <bits/stdc++.h>
using namespace std;
int linear_search(int arr[],int arr_size,int search_element){

    for(int i=0; i<arr_size; i++){
        if(arr[i] == search_element){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[] = {5,3,24,55,2,87,33};

    int search_element = 24;
    int result = linear_search(arr,sizeof(arr)/sizeof(arr[0]),search_element);

    if(result == -1){
        cout<<"Element not found"<<endl;
    }else{
        cout<<"Element " << search_element << " is at index " << result<<endl;
    }
    return 0;
}