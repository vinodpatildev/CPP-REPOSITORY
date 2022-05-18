#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> a{1,2,3,4,5,6,7,8,9,10,11,12};
    a.push_back(100);
    vector<int> b;
    cout<<"--";
    cout<<b.size()<<" ";
    cout<<b.capacity()<<"--"<<endl;
    for(int i=0; i<10; i++){
        b.push_back(i+1);
        cout<<"--";
        cout<<b.size()<<" ";
        cout<<b.capacity()<<"--"<<endl;
    }
    // cout<<b.size()<<endl;
    // cout<<b.capacity()<<endl;
    // cout<<b.max_size()<<endl;

    ////////////////////////////////////////////////////////////////
    
}