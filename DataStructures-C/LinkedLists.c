#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct list {
    int e ;
    struct list *next ;
} list ;

int countnodes(list *head){
    if (head == NULL){
        return 0 ;
    }
    if (head->next == NULL){
        return 1 ;
    }
    else {
        int count = 0 ;
        list *ptr = head ;
        while(ptr != NULL){
            ptr = ptr->next ;
            count += 1 ;
        }
        return count ;
    }
}


void addhead(list **head, int e) {
  if (*head == NULL) {
    *head = malloc(sizeof(list));
    (*head)->next = NULL;
    (*head)->e = e;
  }
  else {
    list *tmp = malloc(sizeof(list));
    tmp->next = *head;
    tmp->e = e;
    *head = tmp;
  }
}


list *addhead2(list *head,int e){
    if (head == NULL){
      head = malloc(sizeof(list));
      head->e = e ;
      head->next = NULL ;
      return head ;
    }
    else {
      list *tmp = malloc(sizeof(list));
      tmp->e = e ;
      tmp->next = head ;
      head = tmp ;
      return head ;
    }
}



bool addmid(list *head ,int e , int pos){
  if ((pos<1) || (pos>countnodes(head))){
    return false ;
  }
  if (head == NULL){
    addhead(&head,e);
    return true ;
  }
  else {
    list *ptr = head ;
    int count = 1 ;
    while (ptr->next != NULL){
      if (count == pos){
        break ;
      }
      ptr = ptr->next ;
      count++ ;
    }
    list *tmp = malloc(sizeof(list));
    tmp->next = ptr->next ;
    ptr->next = tmp ;
    return true ;
  }
}



void addend(list *head, int e){
  if (head == NULL){
    addhead(&head,e);
  }
  else {
    list *tmp = malloc(sizeof(list));
    tmp->next = NULL ;
    tmp->e = e ;
    list  *ptr = head ;
    while (ptr->next != NULL){
      ptr = ptr->next ;
    }
    ptr->next = tmp ;
  }
}

bool search(list *head, int x){
    list *ptr = head ;
    while (ptr != NULL)
    {
        if (ptr->e == x){
            return true ;
        }
        ptr = ptr->next ;
    }
    return false ;
}

int occurences(list *head, int x){
    int occur = 0 ;
    list *ptr = head ;
    while (ptr != NULL)
    {
        if (ptr->e == x){
            occur += 1 ;
        }
        ptr = ptr->next ;
    }
    return occur;
}


int grabindex(list *head, int index ){
    if ((head == NULL) || (index < 0) || (index >= countnodes(head))){
        return ;
    }
    list *ptr = head ;
    int count = 0 ;
    while (ptr->next != NULL)
    {
        if (count == index){
            return ptr->e ;
        }
        ptr = ptr->next ;
        count++ ;
    }
    return ptr->e ;
}


void pophead(list **head){
    if ((*head) == NULL){
        return ;
    }
    else {
        list *neww = (*head)->next ;
        free(*head);
        *head = NULL ;
    }
}


list *pophead2(list *head){
    if (head == NULL){
        return NULL ;
    }
    else {
        list *new_head = head->next ;
        free(head) ;
        return new_head ;
    }
}


void popmid(list *head ,int pos){
    if ((pos >= countnodes(head))||(pos < 1) || (head == NULL)){
        return ;
    }
    else {
        list *ptr = head ;
        int count = 0 ;
        while(ptr->next->next != NULL){
            if (pos == count){
                break ;
            }
            ptr = ptr->next ;
            count += 1 ;
        }
        list *tmp = ptr->next ;
        ptr->next = ptr->next->next ;
        free(tmp);
        tmp = NULL ;
    }
}


void popval(list *head , int x){
    if (head == NULL){
        return ;
    }
    if (head->next == NULL){
        if (head->e == x){
          pophead(&head);
        }
    }
    else {
        list *ptr = head ;
        int count = 0 ;
        while (ptr->next != NULL)
        {
            if (ptr->e == x){
                popmid(ptr,count);
            }
            count += 1 ;
            ptr = ptr->next ;
        }
    }
}


void poptail(list *head){
    if ((head == NULL) || (head->next == NULL)){
            return ;
    }
    else {
        while(head->next->next != NULL){
            head = head->next ;
        }
        free(head->next);
        head->next = NULL ;
    }
}


void showall(list *head){
  if (head != NULL){
    list *ptr = head ;
    while(ptr->next != NULL){
      printf("%d",ptr->e);
      ptr = ptr->next ;
    }
  }
}


int main(){
    list *head = NULL;
    addhead(&head,1);
    /* You can start using the functions now */
    exit(0);
}