#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

    struct Node* f = NULL;
    struct Node* r = NULL;

void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("ELEMENT: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(){
    if(f==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node * n){
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int val){
    struct Node *n ;
    n=(struct Node *)malloc(sizeof(struct Node));
    if(isFull(n)){
        printf("Queue is Full");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
        r->next=n;
        r=n;
        }
    }
}

int dequeue(){
    int val=-1;
    if(isEmpty(f)){
        printf("Queue is empty");
    }
    else{
    struct Node *ptr=f ;
    f=f->next;
    val=ptr->data;
    free(ptr);
    return val;
    }
}


int main(){

    linkedListTraversal(f);
    enqueue(5);
    enqueue(15);
    enqueue(20);
    enqueue(23);
    enqueue(25);
    dequeue();
    dequeue();
    dequeue();
    linkedListTraversal(f);

    return 0;
}