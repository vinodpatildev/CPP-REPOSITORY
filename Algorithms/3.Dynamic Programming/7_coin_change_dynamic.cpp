#include<bits/stdc++.h>
using namespace std;
int coin_change(vector<int>& coins, int size, int sum){
    int s1 = sum+1;
    int s2 = size;
    vector<vector<int>> map(s1,vector<int>(s2,-1));

    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(i==0){
                map[i][j]=1;
            }else{
                int x = (i-coins[j] >=0)? map[i-coins[j]][j] : 0;
                int y = (j>=1)? map[i][j-1] : 0;
                map[i][j]= x + y;
            }
        }
    }cout<<endl;
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            cout<<map[i][j]<<"  ";
        }cout<<endl;
    }
    return map[s1-1][s2-1];
    
}
int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 4;
    
    cout<<"Coin Change Ways :\n"<<coin_change(coins,coins.size(),sum)<<endl;
    return 0;
}