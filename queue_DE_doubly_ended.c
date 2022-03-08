#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

void queueTraversal(struct queue *q){
    while(q->f!=q->r){
        q->f++;
        printf("Element: %d\n",q->arr[q->f]);
    }
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    else {
        return 0;
    }

}

void enqueue_R(struct queue * q,int val){
    if(isFull(q)){
        printf("Queue Overflow!!Enqueue not possible\n");
    }
    else{
        q->r++; 
        q->arr[q->r]=val;
    }
}
void enqueue_F(struct queue * q,int val){
    if(isFull(q)){
        printf("Queue Overflow!!Enqueue not possible\n");
    }
    else if(q->f==-1){
        printf("Enqueue is front is not possible\n");
    }
    else{
        q->arr[q->f]=val;
        q->f--;
    }
}

int dequeue_F(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int dequeue_R(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("The queue is empty\n");
    }
    else{
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

int main(){
    struct queue *q =(struct queue*)malloc(sizeof(struct queue));
 
    q->size=10;
    q->f=-1;
    q->r=-1;
    q->arr=(int *)malloc(sizeof(int)*(q->size));

    queueTraversal(q);
    enqueue_R(q,10);
    enqueue_R(q,20);
    enqueue_R(q,30);
    enqueue_R(q,40);
    enqueue_R(q,50);
    dequeue_F(q);
    dequeue_R(q);
    enqueue_F(q,100);
    queueTraversal(q);
    
    return 0;
}