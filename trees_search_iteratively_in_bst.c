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

int is_bst(struct Node * root)
{
    if (root == NULL)
        return 1;
    if (root->left != NULL && root->left->data >= root->data)
        return 0;
    if (root->right != NULL && root->right->data <= root->data)
        return 0;
    if (!is_bst(root->left) || !is_bst(root->right))
        return 0;
    return 1;
}

struct Node * search_iter(struct Node * root,int key){
    while(root!=NULL){
    if(root->data==key){
        return root;
    }
    else if(key<root->data){
        root=root->left;
    }
    else{
        root=root->right;
    }
}
return NULL;
}

int main(){

    struct Node * p = createNode(5);
    struct Node * p1 = createNode(3);
    struct Node * p2 = createNode(6);  
    struct Node * p3 = createNode(1);  
    struct Node * p4 = createNode(4);  

    p->left=p1;
    p->right=p2;

    p1->left=p3;
    p1->right=p4;

    struct Node * n=search_iter(p,1);
    if(n!=NULL){
        printf("Found : %d",n->data);
    }
    else{
        printf("Data not found");
    }

    // preorder_traversal(p);
    // postorder_traversal(p);
    // inorder_traversal(p);
    // printf("%d",is_bst(p));

    return 0;
}