#include<bits/stdc++.h>
using namespace std;
int min_cost_path(vector<vector<int>>& cost,int m, int n){
    int s1 = m+1;
    int s2 = n+1;
    vector<vector<int>> MCP(s1,vector<int>(s2,-1));

    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(i==0){
                MCP[i][j] = cost[i][j];
            }else if(j==0){
                MCP[i][j] = MCP[i-1][j]+cost[i][j];
            }else{
                MCP[i][j] = min(min(MCP[i-1][j],MCP[i][j-1]),MCP[i-1][j-1])+cost[i][j];
            }
        }
    }
    // cout<<endl;
    // for(int i=0; i<s1; i++){
    //     for(int j=0; j<s2; j++){
    //         cout<<MCP[i][j]<<" ";
    //     }cout<<endl;
    // }
    return MCP[m][n];
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