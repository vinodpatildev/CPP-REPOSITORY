#include<bits/stdc++.h>
using namespace std;
int* calculate_z(string input){
    int i,left=0,right=0;
    int *zarr = new int[input.size()];
    zarr[0] = 0;

    for(i=1; i<input.size(); i++){
        if(i>right){
            left=right=i;
            while(right<input.size() && input[right] == input[right-left]){right++;}
            zarr[i] = right-left;
            right--;
        }else{
            if(zarr[i-left] + i < right+1 ){
                zarr[i] = zarr[i-left];
            }else{
                left=i;
                while(right<input.size() && input[right] == input[right-left]){right++;}
                zarr[i] = right-left;
                right--;
            }
        }
    }
    return zarr;
} 
void z_algorithm(string text, string pattern){
    string zstr = pattern+"$"+text;

    int *zarr = calculate_z(zstr);
    for(int i=1; i<zstr.size(); i++){
        if(zarr[i]==pattern.size()){
            cout<<i-pattern.size()-1<<" ";
        }
    }
    cout<<endl;
}
int main(){
    string text = "aaabcskdjfaaakdjaaabcdjfsjadaaabslkfjkldsaaabc";
    string pattern = "abc";

    z_algorithm(text,pattern);
    cout<<text.size()<<endl;
    return 0;
}