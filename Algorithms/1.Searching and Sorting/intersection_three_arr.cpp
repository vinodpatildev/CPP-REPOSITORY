#include<bits/stdc++.h>
using namespace std;
int traverseTill(int *arr,int index, int target){
    while(arr[index]<target){
        index++;
    }
    return index;
}
void findCommon(int *arr1, int *arr2, int *arr3, int size1, int size2, int size3){
    if(size1==0 || size2==0 || size3==0){
        return;
    }
    int i=0,j=0,k=0,prev=INT_MIN;
    while(i<size1 && j<size2 && k<size3){
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
            if(arr1[i] != prev){
                cout<<arr1[i]<<" ";
                prev = arr1[i];
            }
            i++;
            j++;
            k++;
        }else{
            int target = max(max(arr1[i],arr2[j]),arr3[k]);
            i = traverseTill(arr1,i,target);
            j = traverseTill(arr2,j,target);
            k = traverseTill(arr3,k,target);
        }
    }  
}
int main()
{
    int ar1[] = {1, 5, 5, 10, 20, 40, 80, 100};
    int ar2[] = {5, 5, 6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 5, 5, 15, 20, 30, 70, 80, 100, 120};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}