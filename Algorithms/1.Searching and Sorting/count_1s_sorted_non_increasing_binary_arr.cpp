#include<bits/stdc++.h>
using namespace std;
int countOnes(bool* arr,int left, int right){
    int index = -1;
    int mid;
    while(left<=right){
        mid = left +(right-left)/2;
        // cout<<"mid :"<<mid<<endl;
        if(arr[mid]==true && arr[mid+1]==false){
            index = mid;
            break;
        }else if(arr[mid]==1){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return index+1;
}
int main()
{
   bool arr[] = {1, 1, 1, 1, 0, 0, 0};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << "Count of 1's in given array is " << countOnes(arr, 0, n-1);
   return 0;
}