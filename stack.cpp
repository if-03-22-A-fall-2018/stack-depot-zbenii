#include "stack.h"

struct Node{
  void* data;
  Node* next;
};

struct StackImplementation{
  Node* head;
  Node* tail;
};

Stack create_stack(){
  Stack newStack=(Stack)smalloc(sizeof(struct StackImplementation));
  newStack->head=0;
  newStack->tail=0;
  return newStack;
}


void delete_stack(Stack stack){
  while(stack->head!=0)
  {
    Node* head=stack->head;
    stack->head=head->next;
    sfree(head);
  }
  sfree(stack);
}


void push_stack(Stack stack, void *data){
  Node* node=(Node*)smalloc(sizeof(struct Node));
  node->data=data;
  if(stack->head==0)
  {
    stack->head=node;
    stack->tail=node;
    stack->tail->next=0;
  }
  else
  {
    node->next=stack->head;
    stack->head=node;
  }
}


int get_count(Stack stack){
  int count=0;
  Node* currNode=stack->head;
  while(currNode!=0)
  {
    currNode=currNode->next;
    count++;
  }
  return count;
}


void* pop_stack(Stack stack){
  if(stack->head!=0)
  {
    Node* deleteNode=stack->head;
    stack->head=stack->head->next;
    if(stack->head==0)
    {
      stack->tail=0;
    }

    void* deletedData=deleteNode->data;
    sfree(deleteNode);
    return deletedData;
  }

  return 0;
}


void* peek_stack(Stack stack){
  if(stack->head!=0)
  {
    return stack->head->data;
  }
  return 0;

}
