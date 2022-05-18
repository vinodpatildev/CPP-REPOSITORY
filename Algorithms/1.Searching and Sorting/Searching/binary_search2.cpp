#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int binary_search(int arr[],int leftIndex,int rightIndex, int search_element){
    while(leftIndex <= rightIndex){
        int mid = leftIndex + (rightIndex - leftIndex)/2;

        if(arr[mid] == search_element){
            return mid;
        }
        if(arr[mid] > search_element){
            rightIndex = mid - 1;
        }else{
            leftIndex = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,3,4,5,66,78,89,90,98,112,134};

    int search_element;
    while(search_element != -1){
        cout<<"Enter search element :";
    cin>>search_element;
    int result = binary_search(arr, 0 ,(sizeof(arr)/sizeof(arr[0]))-1, search_element);

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