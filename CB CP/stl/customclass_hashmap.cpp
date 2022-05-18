#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string firstName;
    string lastName;
    string roll_no;
    Student(string f,string l, string r){
        firstName = f;
        lastName = l;
        roll_no = r;
    }
    bool operator==(const Student &s) const{
        return roll_no == s.roll_no;
    }
};
class HashFunction{
    public:
    size_t operator()(const Student &s) const {
        return s.firstName.length() + s.lastName.length();
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    unordered_map<Student,int,HashFunction> map;

    Student s1("Vinod","Patil","118");
    Student s2("Anurag","Kule","109");
    Student s3("Yogesh", "Kakade","140");  
    Student s4("Vinod","Patil","114");
    
    map[s1] = 100;
    map[s2] = 110;
    map[s3] = 111;
    map[s4] = 99;
    
    for(auto item: map){
        cout<<item.first.firstName<<" "<<item.first.lastName<<" "<<item.second<<endl;
    } 
    cout<<map[s4]<<endl;
    return 0;
}