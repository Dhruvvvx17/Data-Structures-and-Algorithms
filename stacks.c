#include<stdio.h>
#include<stdlib.h>
#define MAX 5   //The code creates a fixed size stack at once. If full, more memory is allocated.

typedef struct stack{
    int *a;
    int size;
    int used_size;
}stack;

void init(stack *s);
void allocate(stack *s);
void push(stack *s,int data);
void pop(stack *s);
void display(stack *s);
void clear(stack *s);

void init(stack *s){
    s->size = 0;
    s->used_size = -1;
    return;
}

void allocate(stack *s){
    if(s->size == 0){
        s->a = (int*)malloc(sizeof(int)*MAX);
        s->size = MAX;
    }
    else if(s->used_size == (s->size - 1)){
        s->a = (int*)realloc(s->a,2*(s->size)*sizeof(int));
        s->size = 2*(s->size);
    }
    return;
}

void push(stack *s,int data){
    allocate(s);
    s->used_size++;
    s->a[s->used_size] = data;
    printf("%d pushed successfully\n",data);
    return;
}

void pop(stack *s){
    if(s->used_size == -1){
        printf("Underflow\n");
        return;
    }
    int top = s->a[s->used_size];
    s->used_size--;
    printf("%d popped successfully\n",top);
    return;
}

void display(stack *s){
    if(s->used_size == -1){
        printf("Underflow\n");
        return;
    }
    printf("Stack contents: \n");
    for(int i=(s->used_size);i>=0;i--){
        printf("\t\t%d\n",s->a[i]);
    }  
    return;
}

void clear(stack *s){
    free(s->a);
    init(s);
    printf("Stack cleared\n");
    return;
}

void main(){
    int loop=1;
    int choice,data;
    stack stack;
    init(&stack);
    printf("\n\t-------\n\t STACK\n\t-------\n");
    while(loop){
        printf("\n----------------\n1. Push\n2. Pop\n3. Display\n4. Clear\n5. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){

        case 1: //push
            printf("Enter element: ");
            scanf("%d", &data);
            push(&stack, data);
            break;

        case 2: //pop
            pop(&stack);
            break;

        case 3: //display
            display(&stack);
            break;

        case 4: //clear
            clear(&stack);
            break;

        case 5: //exit
            loop = 0;
            clear(&stack);
            break;        
        }
    }
}