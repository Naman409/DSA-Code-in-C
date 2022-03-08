#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("ELEMENT: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * insertionAtFirst(struct Node * head,int data){
        struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->next=head;
        ptr->data=data;
        return ptr;
}

struct Node * insertioninbetween(struct Node *head,int data,int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;

    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAfterNode(struct Node *head,struct Node *prevnode,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
    
}

struct Node * insertAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p = head;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->next=NULL;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 30;
    fourth->next = NULL;

    printf("Linked List before Insertion\n");
    linkedListTraversal(head);
    // head = insertionAtFirst(head,50);
    // head = insertioninbetween(head,200,2);
    // head = insertAtEnd(head,89);
    // head = insertAfterNode(head,second,100);
    printf("\nLinked List after Insertion\n");
    linkedListTraversal(head);
    return 0;
}   