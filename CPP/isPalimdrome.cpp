#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
  };

bool isPalimdrome(ListNode* head){
  vector<int> nums;
  if(node==NULL){
    return true;
  }
  ListNode *temp = head;
  while(temp){
    nums.push_back(temp->val);
    temp=temp->next;
  }
  bool res= true;
  for(int i=0;i<=(nums.size()/2);i++){
    res = res && (nums[i]==nums[nums.size()-i-1]);
  }
  return res;
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
  addNode(&head,2);
  addNode(&head,1);
  while(head){
    cout<<head->val<<" ";
    head=head->next;
  }

  cout<<endl;
  return 0;
}
