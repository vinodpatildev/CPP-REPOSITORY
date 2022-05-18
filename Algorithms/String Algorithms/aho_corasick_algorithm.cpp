#include <bits/stdc++.h>
using namespace std;
class Trie{
    public:
    class Node{
        public:
        char data;
        bool isTerminal;
        unordered_map<char,Node*> child;
        Node(char ch){
            data = ch;
            isTerminal = false;
        }
    };
    Node* root = NULL;
    int numWords;
    Trie(){
        root = new Node('\0');
        numWords=0;
    }
    void insert(string str){insert(str,0,root);}
    bool search(string str){return search(str,0,root);}
    void remove(string str){remove(str,0,root);}
    void display(){
        cout<<"--------------------------------"<<endl;
        display(root,"");
        cout<<"--------------------------------"<<endl;
    }
    
    void insert(string str, int index, Node* node){
        if(index==str.size()){node->isTerminal = true;return;}
        if(node->child[str[index]] == 0){
            node->child[str[index]] = new Node(str[index]);
        }
        insert(str,index+1,node->child[str[index]]);
    }
    bool search(string str, int index, Node* node){
        if(index==str.size()){return node->isTerminal;}
        if(node->child[str[index]]){
            return search(str,index+1,node->child[str[index]]);
        }
        return false;
    }
    bool remove(string str, int index, Node* node){
        if(index==str.size()){
            node->isTerminal = false;
            return node->child.empty();
        }
        if(remove(str,index+1,node->child[str[index]])){
            delete node->child[str[index]];
            node->child.erase(str[index]);
            return node->child.empty();
        }
        return false;
    }
    void display(Node* node,string str){
        if(node->isTerminal){
            cout<<str<<endl;
        }
        for(auto element : node->child){
            display(element.second,str+element.first);
        }
    }
};
void aho_corosick_algorithm(string text,string pattern){
    Trie T
}

int main(){
    string text = "aaabcskdjfaaakdjaaabcdjfsjadaaabslkfjkldsaaabc";
    string pattern = "abc";

    aho_corasick_algorithm(text,pattern);
    return 0;
}