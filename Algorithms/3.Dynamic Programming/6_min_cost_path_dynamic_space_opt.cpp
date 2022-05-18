#include<bits/stdc++.h>
using namespace std;
int min_cost_path(vector<vector<int>>& cost,int m, int n){
    int s1 = cost.size();
    int s2 = cost[0].size();
    for(int i=1; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(j==0){
                cost[i][j] = cost[i-1][j]+cost[i][j];
            }else{
                cost[i][j] = min(min(cost[i-1][j],cost[i][j-1]),cost[i-1][j-1])+cost[i][j];
            }
        }
    }
    return cost[m][n];
}
int main()
{
   vector<vector<int>> cost = { {1, 2, 3, 7, 1, 2, 3, 7, 1, 2, 3, 7, 1, 2, 3, 7},
                                {1, 7, 3, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 7},
                                {1, 1, 1, 1, 1, 2, 3, 7, 1, 7, 3, 4, 1, 1, 1, 1},
                                {1, 2, 3, 7, 1, 2, 3, 7, 1, 7, 3, 4, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 2, 3, 7, 1, 1, 1, 1, 1, 2, 3, 7},
                                {1, 7, 3, 4, 1, 1, 1, 1, 1, 2, 3, 7, 1, 2, 3, 7} };
    // vector<vector<int>> map(cost.size()+1,vector<int>(cost[0].size(),-1));
    cout<<"Min Cost :"<<min_cost_path(cost, 5, 2)<<endl;
    return 0;
}