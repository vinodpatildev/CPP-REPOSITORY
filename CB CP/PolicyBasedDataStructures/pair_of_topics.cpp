#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    PBDS St;

    int n;
    cin>>n;

    long long *a = new long long[n];
    long long *b = new long long[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    long long element;
    long long answer = 0;
    for(long long i=0; i<n; i++){
        element = a[i] - b[i];
        answer += St.order_of_key(make_pair(element,-1));
        St.insert(make_pair(-element,i));
    }      
    cout<<answer<<endl;
    return 0;
}