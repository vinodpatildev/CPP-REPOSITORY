#include<bits/stdc++.h>
using namespace std;
void print_arr(vector<int>& arr){
    int size = arr.size();
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void counting_sort(vector<int>& arr, int d){
    
    int max = 9;
    int min = 0;
    int range = max-min+1;

    vector<int> count(range),output(arr.size());
    int k = 1;
    for(int i=0; i<arr.size(); i++){
        count[(arr[i]/(int)(pow(10,d)))%10]++;
        // cout<<(arr[i]/(int)(pow(10,d)))%10<<" ";
    }
    // cout<<endl;
    // cout<<"pass "<<k++<<endl;
    for(int i=1; i<range; i++){
        count[i] += count[i-1];
    }
    // cout<<"pass "<<k++<<endl;
    for(int i=range-1; i>0; i--){
        count[i] = count[i-1];
        count[i-1] = 0;
    }
    // cout<<"pass "<<k++<<endl;
    for(int i=0; i<arr.size(); i++){
        output[count[(arr[i]/(int)(pow(10,d)))%10]] = arr[i];
        count[(arr[i]/(int)(pow(10,d)))%10]++;
    }
    // cout<<" output ";
    // print_arr(output);
    // cout<<"pass "<<k++<<endl;
    for(int i=0; i<arr.size(); i++){
        arr[i] = output[i];
    }
    // cout<<"pass "<<k++<<endl;
}
void radix_sort(vector<int>& arr){
    int max = *max_element(arr.begin(),arr.end());
    int i = 0;
    while(max){
        counting_sort(arr,i++);
        max = max/10;
        // cout<<"Array  :";
        // print_arr(arr);
    }
}
int main(){
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    cout<<"Array Before Sorting :";
    print_arr(arr);

    radix_sort(arr);

    cout<<"Array After  Sorting :";
    print_arr(arr);
}