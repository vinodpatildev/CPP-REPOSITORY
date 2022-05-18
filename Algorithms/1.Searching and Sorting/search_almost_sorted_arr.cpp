#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int binary_search(int arr[],int leftIndex,int rightIndex, int search_element){
    if(leftIndex <= rightIndex){
        int mid = leftIndex + (rightIndex - leftIndex)/2;

        if(arr[mid] == search_element){
            return mid;
        }else if(mid-1 >= leftIndex && arr[mid-1] == search_element){
            return mid-1;
        }else if(mid+1 <= rightIndex && arr[mid+1] == search_element){
            return mid+1;
        }
        if(arr[mid] > search_element){
            return binary_search(arr,leftIndex,mid-1,search_element);
        }else{
            return binary_search(arr,mid+1,rightIndex,search_element);
        }
    }
    return -1;
}
int main(){
    int arr[] = {10, 3, 40, 20, 50, 80, 70};

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