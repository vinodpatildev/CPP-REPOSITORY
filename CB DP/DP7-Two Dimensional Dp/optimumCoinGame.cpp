#include<bits/stdc++.h>
using namespace std;
pair<int,int> modi(vector<int> &coins,int left,int right);
pair<int,int> trump(vector<int> &coins,int left,int right);
pair<int,int> modi(vector<int> &coins,int left,int right){
    if(left==right){return make_pair(coins[left],0);}
    pair<int,int> p1,p2;
    p1 = trump(coins,left+1,right); p1.first += coins[left];
    p2 = trump(coins,left,right-1); p2.first += coins[right];

    return (p1.first-p1.second) > (p2.first-p2.second) ? p1:p2;
}
pair<int,int> trump(vector<int> &coins,int left,int right){
    if(left==right){return make_pair(0,coins[left]);}
    pair<int,int> p1,p2;
    p1 = modi(coins,left+1,right); p1.second += coins[left];
    p2 = modi(coins,left,right-1); p2.second += coins[right];

    return (p1.first-p1.second) > (p2.first-p2.second) ? p1:p2;
}

int game(vector<int> &coins){
    pair<int,int> ans = modi(coins,0,coins.size()-1);
    return ans.first-ans.second;
}
int main(){
    vector<int> coins = {7,3,2,5,8,4};
    
    cout<<"Ans :"<<game(coins)<<endl;
    return 0;
}