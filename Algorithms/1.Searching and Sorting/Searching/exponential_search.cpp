#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int binary_search(int arr[],int arr_size, int search_element){
    int index, power;

    for(power = 1; power < arr_size; power <<= 1);

    for(index = 0; power; power >>= 1){
        if(index + power < arr_size && arr[index + power] <= search_element){
            index += power;
        }
    }

    if(arr[index] == search_element){
        return index;
    }
    return -1;
}
int exponential_search(int arr[],int arr_size,int search_element){
    int i = 1;
    for(i=1; i<=arr_size && arr[i-1]<search_element; i = 2*i);
    int res = binary_search(&arr[i/2],min(i-i/2,arr_size-i/2),search_element);
    return res == -1?-1:(i/2) + res;
}
int main(){
    int arr[] = {1,3,4,5,66,78,89,90,98,112,134};

    int search_element;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        search_element = arr[i];
    int result = exponential_search(arr, (sizeof(arr)/sizeof(arr[0])), search_element);

    if(result == -1){
        cout<<"search element :"<<search_element<<" not found"<<endl;
    }else{
        cout<<"search element :"<<search_element<< " index " << result<<endl;
    }
    }
    return 0;
} 