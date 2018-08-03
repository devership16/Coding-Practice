#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
  };

ListNode* reverseList(ListNode* head){
  if (head==NULL|| head->next==NULL){
    return head;
  }
  ListNode* prev=NULL;
  ListNode* temp;
  while(head){
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}

void addNode(ListNode** head, int val){
  struct ListNode* last = *head;
  struct ListNode* newNode = new ListNode;
  newNode->val = val;
  newNode->next = NULL;
  if(*head==NULL){
    *head=newNode;
    return;
  }
  while(last->next!=NULL){
    last = last->next;
  }
  last->next=newNode;
  return;
}
int main(){
  struct ListNode* head = NULL;
  addNode(&head,1);
  addNode(&head,2);
  addNode(&head,3);
  addNode(&head,4);
  addNode(&head,5);
  head=reverseList(head);
  while(head){
    cout<<head->val<<" ";
    head=head->next;
  }
  cout<<endl;
  return 0;
}
