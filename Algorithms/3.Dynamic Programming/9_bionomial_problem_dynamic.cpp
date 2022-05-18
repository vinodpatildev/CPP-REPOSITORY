#include<bits/stdc++.h>
using namespace std;
int bionomial(int n, int k){
    vector<vector<int>> map(n+1,vector<int>(k+1,-1));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i,k); j++){
            if(j==0 || j==i){map[i][j] = 1;}
            else{
                map[i][j] = map[i-1][j-1] + map[i-1][j];
            }
        }
    }
    return map[n][k];
}
int main()
{
    cout<<"Bionomial :\n"<<bionomial(5,2)<<endl;
    return 0;
}