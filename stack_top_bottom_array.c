#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("Stack OverFlow\n");
    }
    else{
    ptr->top++;
    ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack * s,int i){
    int arrayInd = s->top-i+1;
    if(arrayInd < 0){
        printf("Not a valid position\n");
        return -1;
    }
    else{
        return s->arr[arrayInd];
    }
}

int stack_top(struct stack *s){
    return s->arr[s->top];
}
int stack_bottom(struct stack *s){
    return s->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * (s->size));

    printf("%d\n",isFull(s)) ;
    printf("%d\n",isEmpty(s)) ;
    push(s,40);
    push(s,50);
    push(s,50);
    push(s,70);
    push(s,60);
    push(s,57);
    push(s,58);
    push(s,50);
    push(s,25);
    push(s,20);
    printf("%d\n",isFull(s)) ;
    printf("%d\n",isEmpty(s)) ;

    // printf("The popped element is %d\n",pop(s));

    for (int j = 1; j <= s->top+1; j++)
    {
    printf("The value at position %d is %d\n",j,peek(s,j));
        
    }

    printf("Stack top is %d\n",stack_top(s));
    printf("Stack bottom is %d\n",stack_bottom(s));
    

    return 0;
}