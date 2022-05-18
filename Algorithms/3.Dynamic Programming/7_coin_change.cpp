#include<bits/stdc++.h>
using namespace std;
int coin_change(vector<int>& cost,vector<vector<int>> &map, int size, int sum,int sk1,int sk2){
    if(sum==0){return 1;}
    if(sum<0){return 0;}
    if(size<=0 && sum>=1){return 0;}

   return coin_change(cost,map,size,sum-cost[size-1],sk1,sk2) + coin_change(cost,map,size-1,sum,sk1,sk2);
    
}
int main()
{
    vector<int> coins = {2, 5, 3, 6};
    int sum = 10;
    vector<vector<int>> map(sum+1,vector<int>(coins.size(),-1));
    cout<<"Coin Change Ways :\n"<<coin_change(coins,map, coins.size(),sum, coins.size(),sum)<<endl;
    return 0;
}