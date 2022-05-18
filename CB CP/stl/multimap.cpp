#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    multimap<char,string> mm;
    int n;
    char c;
    string str;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>c;
        cin>>str;
        mm.insert(make_pair(c,str));
    }
    for(auto it=mm.begin(); it!=mm.end(); it++){
        if((*it).second=="chutiya"){
            mm.erase(it);
        }
    }
    for(auto it:mm){
        cout<<it.first<<" "<<it.second<<endl;
    }        
    return 0;
}