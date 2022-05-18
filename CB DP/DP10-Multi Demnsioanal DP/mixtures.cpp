#include<iostream>
#include<vector>
using namespace std;
int minColorSmoke(vector<int> &colors){
    int size = colors.size(),smoke1,smoke2;
    vector<vector<int>> dp(size+1,vector<int>(size+1,0));
    vector<vector<int>> smoke(size+1,vector<int>(size+1,0));
    for(int i=1; i<=size; i++){
        for(int j=i; j<=size; j++){
            if(i==1){dp[i][j]=colors[j-1];smoke[i][j]=0;}
            else{
                smoke1 = dp[i-1][j-1]*colors[j-1];
                smoke2 = dp[i-1][j]*colors[j-i+1-1];
                if(smoke1<smoke2){
                    dp[i][j] = (dp[i-1][j-1]+colors[j-1])%100;
                    smoke[i][j] = smoke[i-1][j-1] + smoke1;
                    }
                else{
                    dp[i][j] = (dp[i-1][j]+colors[j-i+1-1])%100;
                    smoke[i][j] = smoke[i-1][j] + smoke2;
                    }
            }
        }
    }

    cout<<endl;
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            cout<<dp[i][j]<<" "; 
        }cout<<endl;
    }cout<<endl;
    cout<<endl;
    for(int i=1; i<=size; i++){
        for(int j=1; j<=size; j++){
            cout<<smoke[i][j]<<" "; 
        }cout<<endl;
    }cout<<endl;
    return smoke[size][size];
}
int main(){
    vector<int> color = {40,60,20};  
    cout<<"Ans :"<<minColorSmoke(color)<<endl;
    return 0;
}