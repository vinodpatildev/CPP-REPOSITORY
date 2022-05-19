#include<bits/stdc++.h>
using namespace std;
void swap(char *c1, char *c2){
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
void toCapitalCase(string &str,int index){
    if(str[index]>='a'){str[index] = str[index]-'a'+'A';}
}
void toSmallCase(string &str,int index){
    if(str[index]<='Z'){str[index] = str[index]-'A'+'a';}
}
void fun(string str, int size, int index){
    if(index == size){
        cout<<str<<endl;
        return;
    }
    for(int i=index; i<size; i++){
        swap(&str[i],&str[index]);
        fun(str,size,index+1);
        toCapitalCase(str,index);
        fun(str,size,index+1);
        toSmallCase(str,index);
        swap(&str[i],&str[index]);
    }
}
int main(){
    fun("abc",3,0);
    return 0;
}
