#include<bits/stdc++.h>
using namespace std;
void BinaryStringsComb(int num,string str){
    if(num==0){cout<<str<<endl;return;}
    if(str.size() && str.back()=='1'){BinaryStringsComb(num-1,str+"0");}
    else{
        BinaryStringsComb(num-1,str+"0");
        BinaryStringsComb(num-1,str+"1") ;
    }
}
void SolveCountBinaryStringProblem(int num){
    BinaryStringsComb(num,"");
}
int main(){
    SolveCountBinaryStringProblem(3);
    return 0;
}