#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node * left;
    struct Node * right;
    int height;
};

int maximum(int a,int b){
    return a>b?a:b;
}

int get_height(struct Node * n){
    if(n==NULL)
        return 0;
    return n->height;
}

struct Node * create_node(int key){
    struct Node * n =(struct Node *)malloc(sizeof(struct Node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

int get_balance_factor(struct Node * n){
    if(n==NULL)
        return 0;
    return (get_height(n->left) - get_height(n->right));    
}

struct Node * right_rotate(struct Node * y){
    struct Node * x = y->left;
    struct Node * T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height=maximum(get_height(x->left),get_height(x->right))+1;
    y->height=maximum(get_height(y->left),get_height(y->right))+1;

    return x;
}

struct Node * left_rotate(struct Node * x){
    struct Node * y = x->right;
    struct Node * T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height=maximum(get_height(x->left),get_height(x->right))+1;
    y->height=maximum(get_height(y->left),get_height(y->right))+1;

    return y;
}

struct Node * insert(struct Node * node,int key){
    if(node==NULL)
        return (create_node(key));

    if(key<node->key)
        node->left = insert(node->left,key);
    
    else if(key>node->key)
        node->right= insert(node->right,key);

    node->height=maximum(get_height(node->left),get_height(node->right)) + 1 ;
    int bf = get_balance_factor(node);

    // Left Left Case
    if(bf>1 && key<node->left->key){
        return right_rotate(node);
    }
    // Right Right Case
    if(bf<-1 && key>node->right->key){
        return left_rotate(node);
    }
    // Left Right Case
    if(bf>1 && key>node->left->key){
        node->left=left_rotate(node->left);
        return right_rotate(node);
    }
    // Right Left Case
    if(bf<-1 && key<node->right->key){
        node->right=right_rotate(node->right);
        return left_rotate(node); 
    }

    return node;

}

void preOrder(struct  Node* root){
    if(root!=NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){

    struct Node * root = NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);
    preOrder(root);

    return 0;
}