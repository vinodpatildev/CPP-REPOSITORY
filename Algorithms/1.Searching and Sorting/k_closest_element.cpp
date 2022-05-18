#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l1,int r1, int l2, int r2){
    int arr_size1 = r1 - l1 + 1;
    int arr_size2 = r2 - l2 + 1;

    int *arr1 = new int[arr_size1];
    int *arr2 = new int[arr_size2];
    
    for(int i=0;i<arr_size1;i++){
        arr1[i] = arr[l1+i];
    }
    for(int j=0;j<arr_size2;j++){
        arr2[j] = arr[l2+j];
    }
    int i=0,j=0;
    int k = l1;
    while(i<arr_size1&&j<arr_size2){
        if(arr1[i]<=arr2[j]){
            arr[k++] = arr1[i++];
        }else{
            arr[k++] = arr2[j++];
        }
    }
    while(i<arr_size1){
        arr[k++] = arr1[i++];
    }
    while(j<arr_size2){
        arr[k++] = arr2[j++];
    }
    return;
}
void merge_sort(int arr[],int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,mid+1,r);
    }
}
void print_arr(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> kClosestElement(int *arr, int size, int x,int k){
    vector<int> ans;
    int l = 0;
    int r = size-1;
    int elementIndex = -1;
    int mid;
    while(l<=r){
        mid = l+(r-l)/2;
        if(arr[mid]==x){
            elementIndex = mid;
            l = 0;
            r = size-1;
            break;
        }else if(arr[mid]>x){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout<<"element index " << elementIndex<<endl;

    int i = elementIndex-1;
    int j = elementIndex+1;

    int leftElement;
    int rightElement;
    while(k){
        leftElement = (i>=l)?arr[i]:INT_MIN;
        rightElement = (j<=r)?arr[j]:INT_MAX;
        // cout<<"left element  :"<<leftElement<<" right element  :"<<rightElement<<endl;
        // cout<<"left          :"<<x-leftElement<<" right          :"<<rightElement-x<<endl;
        
        if((x-leftElement)==(rightElement-x)){
            ans.push_back(leftElement);
            k--;i--;
            if(k){
                ans.push_back(rightElement);
                k--;j++;
            }
        }else if(abs(x-leftElement)<abs(rightElement-x)){
            ans.push_back(leftElement);
            k--;i--;
        }else{
            ans.push_back(rightElement);
            k--;j++;
        }
    }
    return ans;
}
int main(){
    int arr[] = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before Sorting : ";
    print_arr(arr,arr_size);

    merge_sort(arr,0,arr_size-1);

    cout<<"After  Sorting : ";
    print_arr(arr,arr_size);

    vector<int> ans = kClosestElement(arr,arr_size,35,4);
    cout<<"K nearest elements to Array : ";
    for(int i=0; i<4; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;    
    return 0;
}