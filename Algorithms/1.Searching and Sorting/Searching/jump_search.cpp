#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int jump_search(int arr[],int size, int search_element){
    // int rt = sqrt(size);
    int step = sqrt(size);
    int prev = 0 ;
    while(arr[min(step,size)-1] < search_element){
        prev = step;
        step += sqrt(size);
        if(prev >= size){
            return -1;
        }
    }
    while(arr[prev]<search_element){
        prev++;
        // if(prev == min(step,size)){
        //     return -1;
        // }
    }
    if(arr[prev] == search_element){
        return prev;
    }
    return -1;
}
int main(){
    int arr[] = {1,3,4,5,66,78,89,90,98,112,134};

    int search_element;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        search_element = arr[i];
    int result = jump_search(arr, (sizeof(arr)/sizeof(arr[0])), search_element);

    if(result == -1){
        cout<<"search element :"<<search_element<<" not found"<<endl;
    }else{
        cout<<"search element :"<<search_element<< " index " << result<<endl;
    }
    }
    return 0;
}