#include<bits/stdc++.h>
using namespace std;
int lis(int *arr,unordered_map<int,int>& map_next, unordered_map<int,int>& map_lis, int size, int k=0){
    if(!map_next[k]){
        int Next = -1,Lis = 0;
        for(int i=k+1; i<size; i++){
            if(Lis>=size-i){
                break;
            }
            if(arr[k] < arr[i]){
                int li = lis(arr,map_next,map_lis,size,i);
                if(li>Lis){
                    Next = i;
                    Lis = li;
                }
            }
        }
        map_next[k] = Next;
        map_lis[k] = Lis+1;
    }
    return map_lis[k];
}
int largest_increasing_subsequence(int *arr, int arr_size){
    pair<int,int> ans;
    ans.first = -1;
    ans.second = 0;
    unordered_map<int, int> map_next;
    unordered_map<int, int> map_lis;
    for(int i=0; i<arr_size; i++){
        if(ans.second >= arr_size-i){
            break;
        }
        int li = (map_next[i])?map_lis[i]:lis(arr,map_next,map_lis,arr_size,i);
        if(li > ans.second){
            ans.first = i;
            ans.second = li;
        }
    }
    int it = ans.first;    
    cout<<"Longest Increasing Sub-sequence : ";
    while(it != -1){
        cout<<arr[it]<<" ";
        it = map_next[it];
    }
    cout<<"\nLongest Incresing Sub-sequence length :"<<ans.second<<endl;
    return ans.second;
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 ,80};
    // int arr[] = {1,2,3,4,5,44,6,7,8,11,9,10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    largest_increasing_subsequence(arr,arr_size);
    return 0;
}