#include<bits/stdc++.h>
using namespace std;
int BinaryStringsComb(int num,string str,vector<int> &dp0,vector<int> &dp1){
    if(num==0){return 1;}
    if(str.size() && str.back()=='1'){
        if(dp0[num]!=-1){return dp0[num];};
        return dp0[num] = BinaryStringsComb(num-1,str+"0",dp0,dp1);}
    else{
        if(dp1[num]!=-1){return dp1[num];};
        return  dp1[num]=BinaryStringsComb(num-1,str+"0",dp0,dp1) + BinaryStringsComb(num-1,str+"1",dp0,dp1); 
    }
}
int SolveCountBinaryStringProblem(int num){
    vector<int> dp0(num+1,-1);
    vector<int> dp1(num+1,-1);
    return BinaryStringsComb(num,"",dp0,dp1);
}
int main(){
    cout<<"Ans :"<<SolveCountBinaryStringProblem(3);
    return 0;
}