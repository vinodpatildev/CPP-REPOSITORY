#include<bits/stdc++.h>
using namespace std;
void print_arr(vector<int>& arr){
    int size = arr.size();
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void counting_sort(vector<int>& arr, int base, int d){
    
    int range = base;

    vector<int> count(range),output(arr.size());
    int k = 1;
    // cout<<"count :";print_arr(count);
    for(int i=0; i<arr.size(); i++){
        count[(arr[i]/(int)(pow(base,d)))%base]++;
        // cout<<(arr[i]/(int)(pow(base,d)))%base<<" ";
    }
    // cout<<endl;
    // cout<<"count :";print_arr(count);
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
        output[count[(arr[i]/(int)(pow(base,d)))%base]] = arr[i];
        count[(arr[i]/(int)(pow(base,d)))%base]++;
    }
    // cout<<" output ";
    // print_arr(output);
    // cout<<"pass "<<k++<<endl;
    for(int i=0; i<arr.size(); i++){
        arr[i] = output[i];
    }
    // cout<<"pass "<<k++<<endl;
}
void sort_n_numbers_range_nsquare(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(),arr.end());
    int i = 0;
    while(max){
        counting_sort(arr,n,i++);
        max = max/n; //n is the base
        // cout<<"Array  :";
        // print_arr(arr);
    }
}
int main(){
    vector<int> arr = {40, 12, 45, 32, 33, 1, 22};
    cout<<"Array Before Sorting :";
    print_arr(arr);

    sort_n_numbers_range_nsquare(arr);

    cout<<"Array After  Sorting :";
    print_arr(arr);
}