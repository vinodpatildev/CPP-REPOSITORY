#include<bits/stdc++.h>
using namespace std;
void print_arr(vector<int>& arr){
    int size = arr.size();
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void counting_sort(vector<int>& arr){
    int max = *max_element(arr.begin(),arr.end());
    int min = *min_element(arr.begin(),arr.end());
    int range = max-min+1;

    vector<int> count(range),output(arr.size());
    int k = 1;
    for(int i=0; i<arr.size(); i++){
        count[arr[i] - min]++;
    }
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
        output[count[arr[i]-min]] = arr[i];
        count[arr[i]-min]++;
    }
    // print_arr(count);
    // cout<<endl;
    // for(int i=0; i<arr.size(); i++){
    //     output[count[arr[i]-min]-1] = arr[i];
    //     count[arr[i]-min]--;
    // }
    // cout<<"pass "<<k++<<endl;
    for(int i=0; i<arr.size(); i++){
        arr[i] = output[i];
    }
    // cout<<"pass "<<k++<<endl;
}
int main(){
    vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 ,-5 ,-10,-10};
    cout<<"Array Before Sorting :";
    print_arr(arr);

    counting_sort(arr);

    cout<<"Array After  Sorting :";
    print_arr(arr);
}