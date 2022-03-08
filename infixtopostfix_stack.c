#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

char stack_top(struct stack *s){
    return s->arr[s->top];
}

void push(struct stack *ptr,char val){
    if(isFull(ptr)){
        printf("Stack OverFlow\n");
    }
    else{
    ptr->top++;
    ptr->arr[ptr->top]=val;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch){
    if(ch=='*'||ch=='/'||ch=='+'||ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char ch){
    if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
    else return 0;
}

char * infixToPostfix(char * infix){
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=100;
    sp->arr=(char*)malloc(sizeof(char)*sp->size);
    char * postfix = (char*)malloc(sizeof(char)*(strlen(infix)+1));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stack_top(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;


}

int main()
{
    char * exp = "a+b*c-d";
    printf("The postfix expression is %s",infixToPostfix(exp));

    return 0;
}
