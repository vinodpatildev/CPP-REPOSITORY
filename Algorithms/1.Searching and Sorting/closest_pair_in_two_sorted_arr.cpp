#include<bits/stdc++.h>
using namespace std;

pair<int,int> xClosestPair(int *arr1,int *arr2, int size1, int size2, int target){
    pair<int,int> ans;
    int left = 0,right = size2-1;
    int diff = INT_MAX;
    int first_element=0,second_element=0;
    while(left<size1&&right>=0){
        int a = arr1[left];
        int b = arr2[right];
        if(abs(a+b-target)<diff){
            diff = abs(a+b-target);
            first_element = a;
            second_element = b;
        }
        if(a+b > target ){
            right--;
        }else{
            left++;
        }
    }
    ans.first = first_element;
    ans.second = second_element;

    return ans;
}

int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 38;
    pair<int,int> res = xClosestPair(ar1, ar2, m, n, x);
    cout<<"pair :["<<res.first<<","<<res.second<<"]"<<endl;
    return 0;
}