#include<bits/stdc++.h>
using namespace std;

int FriendsPairing(int num){
    if(num==0){return 1;}
    else if(num<0){return 0;}
    vector<int> dp(num+1,-1);
    return FriendsPairing(num-1)+(num-1)*FriendsPairing(num-2);
}
int main(){
    cout<<"Ans :"<<FriendsPairing(3);
    return 0;
}