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
int main(){
    int arr[] = {1,3,4,5,66,78,89,90,98,112,134};

    int search_element;
    while(search_element != -1){
        cout<<"Enter search element :";
    cin>>search_element;
    int result = binary_search(arr, (sizeof(arr)/sizeof(arr[0])), search_element);

    if(result == -1){
        cout<<"Element not found"<<endl;
    }else{
        cout<<"Element " << search_element << " is at index " << result<<endl;
    }
    getch();
    system("cls");
    }
    return 0;
} 