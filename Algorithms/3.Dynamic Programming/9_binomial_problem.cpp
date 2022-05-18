#include<bits/stdc++.h>
using namespace std;
int p=0;
int bionomial(int n, int k){
    p++;
    if(k>n){return 0;}
    if(k==0 || k==n){return 1;}

    return bionomial(n-1,k-1) +  bionomial(n-1,k);
}
int main()
{
    cout<<"Bionomial :\n"<<bionomial(5,2)<<endl;
    cout<<"P :"<<p<<endl;
    return 0;
}