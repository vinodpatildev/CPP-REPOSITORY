#include <bits/stdc++.h>
using namespace std;
int p = 0;
int minimum(int a, int b, int c){
    return min(min(a,b),c);
}
int minCost(vector<vector<int>> &cost,vector<vector<int>> &map, int m, int n){
    p++;
    if(m==0 && n==0){
        return map[m][n] = cost[m][n];
    }else if(m<0 || n<0){
        return INT_MAX;
    }
    if(map[m][n]==-1){
        return map[m][n] = minimum(minCost(cost,map,m-1,n),minCost(cost,map,m-1,n-1),minCost(cost,map,m,n-1)) + cost[m][n];
    }
    return map[m][n];
}

int main()
{
   vector<vector<int>> cost = { {1, 2, 3, 7, 1, 2, 3, 7, 1, 2, 3, 7, 1, 2, 3, 7},
                                {1, 7, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 7},
                                {1, 1, 1, 1, 1, 2, 3, 7, 1, 7, 3, 4, 1, 1, 1, 1},
                                {1, 2, 3, 7, 1, 2, 3, 7, 1, 7, 3, 4, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 2, 3, 7, 1, 1, 1, 1, 1, 2, 3, 7},
                                {1, 7, 3, 4, 1, 1, 1, 1, 1, 2, 3, 7, 1, 2, 3, 7} };
    vector<vector<int>> map(cost.size()+1,vector<int>(cost[0].size(),-1));
   cout<<"Min Cost :"<<minCost(cost,map, 5, 1)<<endl;
   cout<<"P :"<<p<<endl;
   return 0;
}