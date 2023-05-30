#ifndef QUEUES_IMPORT_H
#define QUEUES_IMPORT_H
#include<stdbool.h>

typedef struct tree {
  int e;
  struct tree *left, *right;
} tree;

typedef struct queue {
  tree *root;
  struct queue *next;
} queue;


bool isEmpty(queue *head){
  if (head == NULL){
    return true ;
  }
}


void enqueue(queue **head,tree *root){
  if (*head == NULL){
    *head = malloc(sizeof(queue));
    (*head)->next = NULL ;
    (*head)->root = root ;
    return ;
  }
  else {
    queue *ptr = *head ;
    while(ptr->next != NULL){
      ptr = ptr->next ;
    }
    queue *tmp = malloc(sizeof(queue));
    tmp->next = NULL ;
    tmp->root = root ;
    ptr->next = tmp ;
  }
}


void dequeue(queue **head, tree **holder){
  if (*head != NULL){
    *holder = (*head)->root ;
    queue *tmp = *head ;
    *head = tmp->next ;
    free(tmp) ;
  }
}

#endif