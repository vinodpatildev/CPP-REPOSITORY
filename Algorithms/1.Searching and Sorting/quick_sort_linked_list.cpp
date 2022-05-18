#include<iostream>
using namespace std;
class SLLNode{
    public:
    int val;
    SLLNode *next;
    SLLNode(){
        val = 0;
        next = NULL;
    }
    SLLNode(int value){
        val = value;
        next = NULL;
    }
};
void printLL(SLLNode *head){
    if(head==NULL){
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    printLL(head->next); 
}

SLLNode* partition(SLLNode* head, SLLNode** sll1, SLLNode** sll2){
    SLLNode* p = head;
    head = head->next;
    p->next = NULL;

    while(head){
        if(head->val <= p->val){
            (*sll1) = head;
            sll1 = &((*sll1)->next);
            head = head->next;
            (*sll1) = NULL;
        }else{
            (*sll2) = head;
            sll2 = &((*sll2)->next);
            head = head->next;
            (*sll2) = NULL;
        } 
    }
    return p;
}
SLLNode* quick_sort_sll(SLLNode* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    SLLNode* SLL1=NULL;
    SLLNode* SLL2=NULL;
    SLLNode* p = partition(head,&SLL1,&SLL2);
    // printLL(SLL1);
    // printLL(p);
    // printLL(SLL2);
    SLL1 = quick_sort_sll(SLL1);
    SLL2 = quick_sort_sll(SLL2);
    // printLL(SLL1);
    // printLL(p);
    // printLL(SLL2);

    if(SLL1){
        head = SLL1;
        while(SLL1->next){
            SLL1 = SLL1->next;
        }
        SLL1->next = p;
        p->next = SLL2;
        return head;
    }

    head = p;
    p->next = SLL2;
    return head;
}
int main(){
    SLLNode *head = new SLLNode(12);
    head->next = new SLLNode(5);
    head->next->next = new SLLNode(1);
    head->next->next->next = new SLLNode(4);
    head->next->next->next->next = new SLLNode(66);
    head->next->next->next->next->next = new SLLNode(2);
    head->next->next->next->next->next->next = new SLLNode(9);
    head->next->next->next->next->next->next->next = new SLLNode(32);
    head->next->next->next->next->next->next->next->next = new SLLNode(6);
    head->next->next->next->next->next->next->next->next->next = new SLLNode(7);

    cout<<"Linked List Before Sorting:";
    printLL(head);

    head = quick_sort_sll(head);  

    cout<<"Linked List After  Sorting:";
    printLL(head);
    return 0;
}