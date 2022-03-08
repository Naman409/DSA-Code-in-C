#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void cllTraversal(struct Node *head){
    struct Node *ptr=head;
    do{
        printf("Element is : %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

struct Node * insertionFirst(struct Node* head,int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node * p = head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head = ptr;

    return head;
    
}

int main(){

    struct Node * head ;
    struct Node * second ;
    struct Node * third ;
    struct Node * fourth ;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 20;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 70;
    third->next = fourth;

    fourth->data = 100;
    fourth->next = head;

    printf("Before\n");
    cllTraversal(head);
    head = insertionFirst(head,500);
    printf("After\n");
    cllTraversal(head);

    return 0;
}