#include<bits/stdc++.h>
using namespace std;
int length_longest_common_subsequence(char* str1, char* str2, int s1, int s2){
    if(s1==0 || s2==0){return 0;}
    if(str1[0]==str2[0]){
        return length_longest_common_subsequence(str1+1,str2+1,s1-1,s2-1)+1;
    }
    return max(length_longest_common_subsequence(str1+1,str2,s1-1,s2),length_longest_common_subsequence(str1,str2+1,s1,s2-1));
}
int main()
{
    char str1[] = "AGGTAB";
    char str2[] = "GXTXAYB";
    
     
    cout<<"Length of LCS is :"<< length_longest_common_subsequence( str1, str2, strlen(str1),strlen(str2)); ;
     
    return 0;
}