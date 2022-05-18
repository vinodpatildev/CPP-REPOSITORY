#include<bits/stdc++.h>
using namespace std;

int waysCoinChange(int sum, vector<int> &coins,int coin){
    if(sum==0){return 1;}
    else if(sum<0){return 0;}
    else if(coin<=0){return 0;}

    return waysCoinChange(sum,coins,coin-1) + waysCoinChange(sum-coins[coin-1],coins,coin);
}
int main(){
    cout<<"Ans :"<<waysCoinChange(5, vector<int>()={1,2,5,10}, 4);
    return 0;
}