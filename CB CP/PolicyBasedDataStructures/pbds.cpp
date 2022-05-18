#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    PBDS St;

    St.insert({29,1});
    St.insert({3,8});
    St.insert({54,12});
    St.insert({11,1});
    St.insert({7,3});
    St.insert({99,7});
    St.insert({64,8});
    St.insert({11,12});

    for(int i=0; i<St.size(); i++){
        cout<<i<<" "<<St.find_by_order(i)->first<<" "<<St.find_by_order(i)->second<<endl;
    }
    
    return 0;
}