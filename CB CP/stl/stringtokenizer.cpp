#include<bits/stdc++.h>
using namespace std;


int main(){
    char s[] = "Vinod is the best programmer.";
    char *ptr = strtok(s," ");
    ptr = strtok(NULL," ");
    cout<<ptr<<endl; 
}