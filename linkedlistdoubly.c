#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * prev ;
    struct Node * next ;
};

void dlltraversal(struct Node * head){
    struct Node *ptr = head;
    while(ptr->next!=NULL){
        printf("Elements : %d\n",ptr->data);
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
        printf("Elements : %d\n",ptr->data);
}

void dllrevtraversal(struct Node *fourth){
    struct Node * ptr= fourth;
    while(ptr->prev!=NULL){
        printf("Elements : %d\n",ptr->data);
        ptr=ptr->prev;
    }
    if(ptr->prev==NULL){
        printf("Elements : %d\n",ptr->data);
    }
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->prev=NULL;
    head->data=10;
    head->next=second;

    second->prev=head;
    second->data=20;
    second->next=third;

    third->prev=second;
    third->data=30;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=40;
    fourth->next=NULL;

    printf("Normal Traversal\n");
    dlltraversal(head);
    printf("Reverse Traversal\n");
    dllrevtraversal(fourth);


    return 0;
}