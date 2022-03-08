#include <stdio.h>
#include <stdlib.h>

struct my_array
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct my_array * a,int tsize,int usize){

    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(sizeof(int)*tsize);
}

void show(struct my_array * a){
    for(int i=0; i< a->used_size;i++){
        printf("%d\n",(a->ptr)[i]);
    }
}

void setval(struct my_array * a){
    int n;
    for(int i=0; i< a->used_size;i++){
        printf("Enter element %d",i );
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}



int main(){
    struct my_array marks;
    create_array(&marks,10,2);
    printf("We are running setval now \n");
    setval(&marks);
    printf("We are running show now \n");
    show(&marks);

    return 0;
}
