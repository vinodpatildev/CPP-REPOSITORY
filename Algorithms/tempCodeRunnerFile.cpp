int length_longest_common_subsequence(string str1, string str2){
    int s1 = str1.size()+1;
    int s2 = str2.size()+1;
    int LCS[][] = new int[2][s2];
    int b=0;
    for(int i=0; i<s1; i++){
        b = i & 1;
        for(int j=0; j<s2; j++){
            if(i==0 || j==0){
                LCS[b][j] = 0;
            }else if(str1[i-1] == str2[j-1]){
                LCS[b][j] = LCS[1-b][j-1] + 1;
            }else{
                LCS[b][j] = max(LCS[1-b][j],LCS[b][j-1]);
            }
        }
    }
    return LCS[b][s2-1];
}