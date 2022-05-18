#include <bits/stdc++.h>
#include <conio.h>
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
int main(){
    Trie tn;
    while(1){
        tn.display();
        int c;
        cout<<"\n\n1. Insert String."<<endl;
        cout<<"2. Remove String."<<endl;
        cout<<"3. Search String."<<endl;
        cout<<"4. Quit."<<endl;
        cout<<"\nEnter Choice :";
        cin>>c;
        cout<<"\n";
        
        switch(c){
            case 1:{
                string s;
                cout<<"String :";
                cin>>s;
                tn.insert(s);
                break;
            }
            case 2:{
                string s;
                cout<<"Removal String :";
                cin>>s;
                tn.remove(s);
                break;
            }
            case 3:{
                string s;
                cout<<"Search String :";
                cin>>s;
                if(tn.search(s)){
                    cout<<"\n\""<<s<<"\" exists."<<endl;
                }else{
                    cout<<"\n\""<<s<<"\" does not exists."<<endl;
                }
                getch();
                break;
            }
            case 4:break;
            default :cout<<"\nEnter Choice Again."<<endl;break;
        }
        if(c==4){break;}
        system("cls");
    }
    
    return 0;
}