#include<bits/stdc++.h>
using namespace std;
int workingOut(int row,int col){
    vector<vector<int>> girl(row,vector<int>(col,-1));
    vector<vector<int>> boy(row,vector<int>(col,-1));
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 && j==0){boy[i][j] = 1;}
            else if(i==0){boy[i][j] = boy[i][j-1] + 1;}
            else if(j==0){boy[i][j] = boy[i-1][j] + 1;}
            else{boy[i][j] = boy[i][j-1] + 1;}
        }
    }
    for(int i=row-1; i<=0; i--){
        for(int j=0; j<col; j++){
            if(i==row-1 && j==0){girl[i][j] = 1;}
            else if(i==row-1){girl[i][j] = girl[i][j-1] + 1;}
            else if(j==0){girl[i][j] = girl[i+1][j] + 1;}
            else{girl[i][j] = girl[i][j-1] + 1;}
        }
    }
    for(int i=row-1; i<=0; i--){
        for(int j=0; j<col; j++){
            if(i==row-1 && j==0){girl[i][j] = 1;}
            else if(i==row-1){girl[i][j] = girl[i][j-1] + 1;}
            else if(j==0){girl[i][j] = girl[i+1][j] + 1;}
            else{girl[i][j] = girl[i][j-1] + 1;}
        }
    }

    // cout<<endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<mat[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    // cout<<endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    return dp[row-1][col-1];
}
int main(){
    int row = 5,col=4;
    cout<<"Ans :"<<workingOut(row,col)<<endl;
    return 0;
}