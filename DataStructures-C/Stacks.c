#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define stackMAX 20
int stackcount = 0 ;
typedef struct stack {
  int e;
  struct stack *next;
} stack;


bool isFull(stack *head){
  if (stackcount == stackMAX -1){
    return true ;
  }
  return false;
}


bool isEmpty(stack *head){
  if (head == NULL){
    return true;
  }
  return false ;
}


void push(stack **head,int e){
  if (isFull(*head)){
    return ;
  }
  if (*head == NULL){
      *head = malloc(sizeof(stack));
      (*head)->next = NULL ;
      (*head)->e =e ;
      stackcount += 1 ;
    }
  else {
    stack *tmp = malloc(sizeof(stack));
    tmp->e = e ;
    tmp->next = *head ;
    *head = tmp ;
    stackcount += 1 ;
  }
}



void pop(stack **head, int *hold){
  if (isEmpty(*head)){
    return ;
  }
  else {
    *hold = (*head)->e ;
    stack *tmp = *head ;
    *head = (*head)->next;
    free(tmp);
    tmp = NULL ;
    stackcount -= 1 ;
  }
}

int main(){
  int *hold = NULL ;
  stack *head = NULL ;
  /* Now able to use the functions */
  return 0 ;
}
