#include<bits/stdc++.h>
using namespace std;

int waysToReachLadder(int num,int k){
    if(num==0){return 1;}
    else if(num<0){return 0;}
    int way = 0;
    for(int i=1;i<=k;i++){
        way += waysToReachLadder(num-i,k);
    }
    return way;
}
int main(){
    cout<<"Ans :"<<waysToReachLadder(10,3);
    return 0;
} 