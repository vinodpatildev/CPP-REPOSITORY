#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1, 1, 1, 2, 3, 3, 3, 3, 4, 5, 6, 6, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    // auto it = find(arr,arr+n,500);
    // int index = it-arr;
    // cout<<"index : "<<index<<endl;

    // bool present = binary_search(arr,arr+n,54);
    // cout<<present<<endl;

    int lb = lower_bound(arr,arr+n,3)-arr;
    int ub = upper_bound(arr,arr+n,3)-arr;

    cout<<"Freq of 3 :"<<ub-lb;

    return 0;
}