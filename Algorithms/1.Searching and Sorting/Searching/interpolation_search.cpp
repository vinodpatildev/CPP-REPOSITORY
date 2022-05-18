#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int interpolation_search(int arr[],int leftIndex,int rightIndex, int search_element){
    if(leftIndex <= rightIndex){
        int pos = leftIndex + ((search_element - arr[leftIndex])*(rightIndex-leftIndex))/(arr[rightIndex]-arr[leftIndex]);

        if(arr[pos] == search_element){
            return pos;
        }
        if(arr[pos] > search_element){
            return interpolation_search(arr,leftIndex,pos-1,search_element);
        }else{
            return interpolation_search(arr,pos+1,rightIndex,search_element);
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
    int result = interpolation_search(arr,0, (sizeof(arr)/sizeof(arr[0]))-1, search_element);

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