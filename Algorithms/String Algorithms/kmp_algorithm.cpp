#include <iostream>
using namespace std;
int* create_pi(string pattern){
    int *pi = new int[pattern.size()];
    pi[0] = 0;
    int i=0,j=1;
    while(j<pattern.size()){
        if(pattern[i]==pattern[j]){
            pi[j] = i+1;
            i++;
            j++;
        }else{
            if(i==0){
                pi[j] = 0;
                j++;
            }else{
                i = pi[i-1];
            }
        }
    }
    return pi;
}
void kmp_algorithm(string text,string pattern){
    int *pi = create_pi(pattern);

    int i=0,j=0;
    while(i<text.size()){
        if(text[i]==pattern[j]){
            if(j==pattern.size()-1){
                cout<<i-j<<" ";
                j = 0;
            }else{j++;}
            i++;
        }else{
            if(j==0){i++;}
            else{j = pi[j-1];}
        }
    }
}

int main(){
    string text = "aaabcskdjfaaakdjaaabcdjfsjadaaabslkfjkldsaaabc";
    string pattern = "abc";

    kmp_algorithm(text,pattern);
    return 0;
}