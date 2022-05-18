#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    int roll_no;  
    Student(int num){
        roll_no = num;
    }
};
class StudentCompare{
    public:
    bool operator()(const Student A,const Student B){
        return A.roll_no < B.roll_no;
    }
};
int main(){
    priority_queue<Student,vector<Student>, StudentCompare> pq;
    pq.push(Student(118));
    pq.push(Student(114));
    pq.push(Student(109));

    while(!pq.empty()){
        cout<<pq.top().roll_no<<" ";
        pq.pop();
    }
    
    return 0;
}