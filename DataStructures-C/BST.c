#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct tree {
    int e ;
    struct tree *left ,*right ;
} tree ;


int max(int a, int b) {
  return (a > b) ? a : b;
}

tree *makeleaf(int e){
    tree *leaf = malloc(sizeof(tree));
    leaf->e = e ;
    leaf->left = NULL ;
    leaf->right = NULL ;
    return leaf ;
}

void insert(tree** head, int e) {
    if (*head == NULL) {
        *head = makeleaf(e);
    } else {
        if ((*head)->e < e) {
            insert(&(*head)->left, e);
        } else {
            insert(&(*head)->right, e);
        }
    }
}


bool _isleaf(tree *root){
    if (root == NULL){
        return false ;
    }
    if ((root->left == NULL) && (root->right == NULL)){
        return true ;
    }
    else {
        return false ;
    }
}

int countleafs(tree *head) {
  if (head == NULL) {
    return 0;
  }

  if (head->left == NULL && head->right == NULL) {
    return 1;
  }

  return countleafs(head->left) + countleafs(head->right);
}



bool isbranch(tree *root){
    if (root == NULL){
        return false ;
    }
    if ((root->left != NULL) && (root->right != NULL)){
        return true ;
    }
    else {
        return false ;
    }
}

bool _isemptytree(tree *root){
    if (root == NULL){
        return false ;
    }
    else {
        return true ;
    }
}

void minimum(tree* head) {
    if (head == NULL) {
        return;
    } else {
        tree* current = head;

        while (current->left != NULL) {
            current = current->left;
        }

        printf("%d", current->e);
    }
}


void preorder(tree *root){
    if (root != NULL){
        printf("%d",root->e);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d",root->e);
        inorder(root->right);

    }
}

void postorder(tree *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->e);
    }
}



int size(tree *root){
    if (root == NULL){
        return 0 ;
    }
    if ((root->left != NULL) && (root->right != NULL)){
        return 1 ;
    }
    else {
        return (size(root->left) + (size(root->right)));
    }
}

int height(tree *root){

    if (root == NULL){
        return 0 ;
    }
    else {
        return (1 + max(height(root->left),height(root->right)));
    }
}


bool seachx(tree *root , int x){
    bool found = true ;
    if (root == NULL){
        return ! found ;
    }
    if (root->e == x){
        return found ;
    }
    else {
        return (seachx(root->left , x)  || seachx(root->right ,x ));
    }
}

tree *connect(int e, tree *left_root , tree *right_root){
     tree *root = malloc(sizeof(tree));
     root->e = e ;
     root->left = left_root ;
     root->right = right_root ;
     return root ;
}




tree *droptree(tree *root){
    if (root == NULL){
        return NULL ;
    }
    else {
        droptree(root->left);
        droptree(root->right);
        free(root);
        root = NULL ;
        return root ;
    }
}



/* Now for the level order traversal a queue is needed
   Although this time the queue contains tree nodes */

#include "queuesImport.h"

void levelorder(tree *root,tree *holder,queue *head){
  if (root == NULL){
    return ;
  }
  else {
    enqueue(&head,root) ;
    while(! isEmpty(head)){
      /* Do some work with the element */
      dequeue(&head,&holder) ;
      if (root->left != NULL){
        levelorder(root->left,holder, head) ;
      }
      if (root->right != NULL){
      levelorder(root->right,holder,head) ;
      }
    }
  }
}


int main(){
    tree *root = NULL ;
    queue *head = NULL ;
    tree *holder = NULL ;
    /* Functions here  */

    exit(0);
}
