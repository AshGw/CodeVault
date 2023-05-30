#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define queueMAX 20
int queuecount = 0 ;
typedef struct queue {
  int e;
  struct queue *next;
} queue;

bool queueisFull(){
  if (queuecount == queueMAX - 1){
    return true ;
  }
  return false ;
}


bool queueisEmpty(queue *head){
  if (head == NULL){
    return true ;
  }
}


void enqueue(queue **head,int e){
  if (queuecount == queueMAX -1)
    return ;
  if (*head == NULL){
    *head = malloc(sizeof(queue));
    (*head)->next = NULL ;
    (*head)->e = e ;
  }
  else {
    queue *ptr = *head ;
    while(ptr->next != NULL){
      ptr = ptr->next ;
    }
    queue *tmp = malloc(sizeof(queue));
    tmp->next = NULL ;
    tmp->e = e ;
    ptr->next = tmp ;
  }
}


void dequeue(queue **head,int *holder){
  if (*head != NULL){
    *holder = (*head)->e ;
    queue *tmp = *head ;
    *head = tmp->next ;
    free(tmp);
    tmp = NULL;
  }
  else {
    return ;
  }
}


int main(){
  queue *head = NULL ;
  int *holder = NULL ;
  /* Functions can be used now */
  return 0 ;
}