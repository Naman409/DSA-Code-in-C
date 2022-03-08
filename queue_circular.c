#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else {
        return 0;
    }

}

void enqueue(struct queue * q,int val){
    if(isFull(q)){
        printf("Queue Overflow!!Enqueue not possible");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue *q =(struct queue*)malloc(sizeof(struct queue));
 
    q->size=5;
    q->f=-1;
    q->r=-1;
    q->arr=(int *)malloc(sizeof(int)*(q->size));

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    if(isFull(q)){
        printf("Queue is full\n");
    }

    
    printf("The dequeued value is %d\n",dequeue(q));
    printf("The dequeued value is %d\n",dequeue(q));
    
    
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    
    if(isFull(q)){
        printf("Queue is full\n");
    }

    return 0;
}