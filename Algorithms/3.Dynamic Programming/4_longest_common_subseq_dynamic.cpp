#include<bits/stdc++.h>
using namespace std;
int length_longest_common_subsequence(string str1, string str2){
    int s1 = str1.size()+1;
    int s2 = str2.size()+1;
    int LCS[s1][s2];
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            if(i==0 || j==0){
                LCS[i][j] = 0;
            }else if(str1[i-1] == str2[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }else{
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    cout<<endl;
    for(int i=0; i<s1; i++){
        for(int j=0; j<s2; j++){
            cout<<LCS[i][j]<<" ";
        }
        cout<<endl;
    }
    
    string ans = "";
    int i=str1.size()-1;
    int j=str2.size()-1;
    while(i>=0 && j>=0){
        if(str1[i]==str2[j]){
            ans = str1[i] + ans;
            i--;j--;
        }else if(LCS[i+1][j+2]>=LCS[i+2][j+1]){
            j--;
        }else{
            i--;
        }
    }
    cout<<"Answer :"<<ans;

    return LCS[s1-1][s2-1];
}
int main()
{
    string str1 = "AMONGISH";
    string str2 = "JAONIGHT”";

    cout<<"Length of LCS is :"<< length_longest_common_subsequence( str1, str2);
     
    return 0;
}