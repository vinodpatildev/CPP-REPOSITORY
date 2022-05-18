#include <iostream>
using namespace std;
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
bool isSorted(int *arr, int size){
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
void Heapify(int *arr, int size, int i){
    int largest = i;
    int left =  2*i + 1;
    int right = 2*i + 2;

    if(left<size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        Heapify(arr,size,largest);
    }
}
void HeapSort(int *arr, int size){
    for(int i=size/2-1; i>=0; i--){
        Heapify(arr,size,i);
    }
    for(int i=size-1; i>0; i--){
        swap(&arr[i],&arr[0]);
        Heapify(arr,i,0);
    }
}
pair<int,int> find_unsorted_subarray(int *arr, int size){
    pair<int,int> ans;
    ans.first = -1;
    ans.second = -1;
    int i;
    for(i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            ans.first = i;
            break;
        } 
    }
    for(i=size-1; i>0; i--){
        if(arr[i]<arr[i-1]){
            ans.second = i;
            break;
        } 
    }
    cout<<ans.first<<" "<<ans.second - ans.first +1 <<endl;
    HeapSort(arr + ans.first, ans.second - ans.first + 1);
    if(!isSorted(arr,size)){
        pair<int,int> res = find_unsorted_subarray(arr, size);
        ans.first = min(ans.first,res.first);
        ans.second = max(ans.second,res.second);
    }
    return ans;
}
void print_arr(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {10, 12, 20, 30, 25,40, 32, 31, 35, 50, 60};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Initial Array :";
    print_arr(arr,arr_size);

    pair<int,int> res = find_unsorted_subarray(arr,arr_size);
    if(res.first != -1){
        cout<<"index "<<res.first<<" index "<<res.second<<endl;
    }

    cout<<"Initial Array :";
    print_arr(arr,arr_size);

    return 0;
}