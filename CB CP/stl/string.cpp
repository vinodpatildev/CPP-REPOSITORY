#include<string>
#include<iostream>
using namespace std;

int main(){
    string s0;
    string s1("Vinod");
    string s2 = "Rahul";
    string s3(s2);
    string s4 = s1;
    char arr[] = {'a','b','c','\0'};
    string s5(arr);
    s0.append("Hi Bikas");
    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    
    
    return 0;
}