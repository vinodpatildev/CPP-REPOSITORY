#include<bits/stdc++.h>
using namespace std;
int edit_distance_subsequence(string str1, string str2){
    int s1 = str1.size()+1;
    int s2 = str2.size()+1;
    int LCS[2][s2];
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(i==0){
                LCS[i][j] = j;
            }else if(j==0){
                LCS[1][j] = i;
            }else if(str1[i-1] == str2[j-1]){
                LCS[1][j] = LCS[1-1][j-1];
            }else{     //Remove---------Insert--------Replace;
                LCS[1][j] = min(min(LCS[1-1][j],LCS[1][j-1]),LCS[1-1][j-1])+1;
            }
            if(j==s2-1 && i!=0){
                LCS[0][j-1] = LCS[1][j-1];
                LCS[0][j] = LCS[1][j];
            }else if(j!=0 && i!=0){
                LCS[0][j-1] = LCS[1][j-1];
            }
        }
        // print the LCS
        // for(int j=0; j<s2; j++){
        //     cout<<LCS[0][j]<<" ";
        // }cout<<endl;
    }
    return LCS[0][s2-1];
}
int main()
{                           
    string str1 = "sunday";
    string str2 = "saturday";


    cout<<"Length of LCS is :"<< edit_distance_subsequence(str1, str2);
     
    return 0;
}