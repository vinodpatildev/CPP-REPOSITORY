#include<bits/stdc++.h>
using namespace std;
int maxProfitWines(vector<int> &wines,int year,int left,int right){
    if(left==right){return year*wines[left];}
    return max(maxProfitWines(wines,year+1,left+1,right)+wines[left]*year, maxProfitWines(wines,year+1,left,right-1)+wines[right]*year);
} 
int maxProfitWines(vector<int> &wines){return maxProfitWines(wines,1,0,wines.size()-1);}
int main(){
    vector<int> wines = {2,3,5,1,4};
    cout<<"Ans : "<<maxProfitWines(wines)<<endl;
    return 0;
}