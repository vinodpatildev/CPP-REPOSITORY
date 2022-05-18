#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int *mat, int i, int j){
    if(j==i){return 0;}
    int count,min=INT_MAX;

    for(int k=i; k<j; k++){
        count = MatrixChainOrder(mat,i,k) + MatrixChainOrder(mat,k+1,j) + mat[i-1]*mat[k]*mat[j];
        if(count<min){min = count;}
    }
    return count;
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);
}