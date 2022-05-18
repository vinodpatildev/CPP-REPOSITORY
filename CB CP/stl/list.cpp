#include<algorithm>
#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l{14,55,12,12,3,44,52}; 
    
    for(auto i:l){
        cout<<i<<"-->";
    }cout<<endl;
    // l.remove(12);
    // l.insert(++ ++ ++ ++ ++l.begin(),99);
    auto it=l.begin();
    while(*it != 3){it++;}
    l.erase(it);
    for(auto i=l.begin(); i!=l.end(); i++){
        cout<<*i<<"-->";
    }cout<<endl;

    return 0;
}