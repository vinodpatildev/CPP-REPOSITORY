#include<iostream>
using namespace std;
class LLNode{
    public:
    int val;
    LLNode *next;
    LLNode(){
        val = 0;
        next = NULL;
    }
    LLNode(int value){
        val = value;
        next = NULL;
    }
};
void printLL(LLNode *head){
    if(head==NULL){
        cout<<endl;
        return;
    }
    cout<<head->val<<" ";
    printLL(head->next); 
}
void FrontBackSplit(LLNode* head,LLNode** LL1,LLNode** LL2){
    LLNode* curr1=head;
    LLNode* curr2=head->next;
    while(curr2->next && curr2->next->next){ 
        curr1 = curr1->next;
        curr2 = curr2->next->next;
    }
    (*LL1) = head;
    (*LL2) = curr1->next;
    curr1->next = NULL;
}
LLNode * sorted_merge(LLNode* LL1, LLNode* LL2){
    LLNode* head;
    if(LL1==NULL){
        return LL2;
    }else if(LL2==NULL){
        return LL1;
    }
    if(LL1->val <= LL2->val){
        head = LL1;
        head->next = sorted_merge(LL1->next,LL2);
    }else{
        head = LL2;
        head->next = sorted_merge(LL1,LL2->next);
    }
    return head;
}

LLNode* merge_sort_LL(LLNode* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    LLNode* LL1;
    LLNode* LL2;
    FrontBackSplit(head, &LL1, &LL2);
    LL1 = merge_sort_LL(LL1);
    LL2 = merge_sort_LL(LL2);
    head = sorted_merge(LL1,LL2);
    return head;
}
int main(){
    LLNode *head = new LLNode(12);
    head->next = new LLNode(5);
    head->next->next = new LLNode(1);
    head->next->next->next = new LLNode(4);
    head->next->next->next->next = new LLNode(66);
    head->next->next->next->next->next = new LLNode(2);
    head->next->next->next->next->next->next = new LLNode(9);
    head->next->next->next->next->next->next->next = new LLNode(32);
    head->next->next->next->next->next->next->next->next = new LLNode(6);
    head->next->next->next->next->next->next->next->next->next = new LLNode(7);

    cout<<"Linked List Before Sorting:";
    printLL(head);

    head = merge_sort_LL(head);  

    cout<<"Linked List After  Sorting:";
    printLL(head);
    return 0;
}







// while(LL1&&LL2){ 
//         if(LL1->val <= LL2->val){
//             (*curr) = LL1;
//             LL1 = LL1->next;
//         }else{
//             (*curr) = LL2;
//             LL2 = LL2->next;
//         }
//         curr = &((*curr)->next);
//         (*curr) = NULL;
//     }
//     if(LL1 != NULL){
//         *curr = LL1;
//     }
//     if(LL2 != NULL){
//         *curr = LL2;
//     }
//     return head;