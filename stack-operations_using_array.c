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
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * (s->size));

    printf("%d\n",isFull(s)) ;
    printf("%d\n",isEmpty(s)) ;

    push(s,30);
    push(s,40);
    push(s,50);
    push(s,50);
    push(s,70);
    push(s,60);
    push(s,57);
    push(s,58);
    push(s,50);
    push(s,25);

    printf("%d\n",isFull(s)) ;
    printf("%d\n",isEmpty(s)) ;

    printf("The popped element is %d",pop(s));

    return 0;
}
