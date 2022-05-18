#include <bits/stdc++.h>
#include<climits>
#include<cstdlib>
#include<conio.h>
using namespace std;
void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
int binary_search(vector<int> &arr,int leftIndex,int rightIndex, int search_element){
    if(leftIndex <= rightIndex){
        int mid = leftIndex + (rightIndex - leftIndex)/2;

        if(arr[mid] == search_element){
            return mid;
        }
        if(arr[mid] > search_element){
            return binary_search(arr,leftIndex,mid-1,search_element);
        }else{
            return binary_search(arr,mid+1,rightIndex,search_element);
        }
    }
    return -1;
}
void print_arr(vector<int> &arr, int left = 0, int right = 0){
    if(!right){
        right = arr.size()-1;
    }
    for(int i=left; i<=right; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(vector<int> &arr,int left,int right, int pivotElement){
    int pivot = binary_search(arr, left, right, pivotElement);
    // cout<<"Pivote Index :"<<pivot;
    // cout<<endl;print_arr(arr,left,right);
    // cout<<"pivot :"<< pivot <<"\n";

    swap(&arr[pivot],&arr[right]);
    int k = left-1;
    for(int i=left; i<=right; i++){
        if(arr[i]<=arr[right]){
            swap(&arr[i],&arr[++k]);
        }
    }
    // cout<<"      :"<< k <<"\n";
    // print_arr(arr,left,right);
    return k;
}
int findMedian(vector<int> &arr, int left, int right)
{   
    sort(&arr[left], &arr[right+1]);
    // print_arr(arr,left,right);  // Sort the array
    return arr[left + (right-left)/2];   // Return middle element
}
int quickSelect(vector<int> &arr, int left, int right, int k){
    if(left <= right){
        int i=0,n = right-left+1;
        vector<int> median((n+4)/5);
        for(i=0; i<n/5; i++){
            // cout<<"findMedian(arr,"<<left+(i*5)<<","<<left+((i+1)*5-1)<<") --";
            median[i] = findMedian(arr,left+(i*5),left+(i+1)*5-1);
            // cout<<median[i]<<"\n";
        }
        if(i<(n+4)/5){
            // cout<<"findMedian(arr,"<<left+(i*5)<<","<<left+(n-1)<<") --";
            median[i] = findMedian(arr,left+(i*5),left+n-1);
            // cout<<median[i]<<"\n";
            i++;
        }
        // print_arr(median); 
        int MedOfMed = (i == 1)? median[i-1] : quickSelect(median,0,i-1,i/2);
        // cout<<"MedOfMed :"<<MedOfMed<<endl; 
        int part = partition(arr,left,right,MedOfMed);
        // cout<<"part :"<<part<<endl;
        if(part == k-1){
            return arr[part];
        }
        if(part > k-1){
            right = part-1;
            // cout<<"quickSelect(arr,"<<left<<","<<right<<","<<k<<")"<<endl;
            return quickSelect(arr,left,right,k);
        }else{
            left = part+1;
            // cout<<"quickSelect(arr,"<<left<<","<<right<<","<<k<<")"<<endl;
            return quickSelect(arr,left,right,k);
        }
    }
    return INT_MAX;
}
int main(){
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26, 22, 25, 1, 17, 0, 2};
    cout<<"Array Before :";
    print_arr(arr);
    int K;
    while(1){
        cout<<"Enter value of K :";
        cin>>K;
        if(K==-1)break;
        cout<<quickSelect(arr,0,arr.size()-1,K)<<endl;

        // cout<<"Array After  :";
        // print_arr(arr);
        // getch();
        // system("cls");
    }
    return 0;
}