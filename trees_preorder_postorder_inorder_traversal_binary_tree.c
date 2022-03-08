#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * left;
    int data;
    struct Node * right;
};

struct Node * createNode(int data){
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder_traversal(struct Node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct Node * root){
    if(root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ",root->data);
    }
}

void inorder_traversal(struct Node * root){
    if(root!=NULL){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

int main(){

    struct Node * p = createNode(10);
    struct Node * p1 = createNode(8);
    struct Node * p2 = createNode(3);  
    struct Node * p3 = createNode(14);  
    struct Node * p4 = createNode(30);  

    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    // preorder_traversal(p);
    // postorder_traversal(p);
    // inorder_traversal(p);

    return 0;
}