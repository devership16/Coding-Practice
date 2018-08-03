#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
  };

void deleteNode(ListNode* node){
  struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
  delete temp;
  return;
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
  addNode(&head,4);
  addNode(&head,5);
  addNode(&head,1);
  addNode(&head,9);
  deleteNode(head->next->next);
  while(head){
    cout<<head->val<<" ";
    head=head->next;
  }
  cout<<endl;
  return 0;
}
