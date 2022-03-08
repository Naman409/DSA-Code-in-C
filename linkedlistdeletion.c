#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * deletionAtFirst(struct Node * head){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node * deletionInBetween(struct Node * head,int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}

struct Node * deleteLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node * deletionofgivenvalue(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value){
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 100;
    head->next = second;

    second->data = 200;
    second->next = third;

    third->data = 350;
    third->next = fourth;

    fourth->data = 500;
    fourth->next = NULL;

    printf("Linked List before Deletion \n");
    linkedListTraversal(head);
    // head = deletionAtFirst(head);
    // head = deletionInBetween(head,2);
    // head = deleteLast(head);
    head = deletionofgivenvalue(head,350);
    printf("Linked List after Deletion \n");
    linkedListTraversal(head);

return 0;

}