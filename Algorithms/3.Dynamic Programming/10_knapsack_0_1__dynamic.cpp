#include<bits/stdc++.h>
using namespace std;
int p=0;
int knapSack(int W, int *wt, int *val,int n){
    vector<vector<int>> map(n+1,vector<int>(W+1,-1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0){map[i][j] = 0;}
            else if(wt[i-1] > j){map[i][j] = map[i-1][j];}
            else{map[i][j] = max(val[i-1] +(j-wt[i-1]>=0? map[i][j-wt[i-1]] : 0) ,map[i-1][j]);}
        }
    }
    cout<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    return map[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}