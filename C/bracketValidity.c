#include<stdio.h>

typedef struct stack{
    char a[50];
    int top;
}stack;

void push(stack *s,char data);
char pop(stack *s);

void push(stack *s, char data){
    if(s->top == 50){
        printf("Overflow\n");
        return;
    }
        s->top++;
        s->a[s->top] = data;
        return;
}

char pop(stack *s){
    if(s->top == -1){
        printf("Underflow\n");
        return '\0';
    }
    return(s->a[s->top--]);
}

void main(){
    stack stack;
    stack.top = -1;
    char exp[50];
    int count = 0;
    printf("Enter the expression: ");
    scanf("%s",exp);
    int i=0;
    //to check if the first element is a closing bracket.
    if (exp[0] == ')' || exp[0] == '}' || exp[0] == ']'){
        printf("Expression is not valid\n");
        return;
        }
    //checking entire expression
    while(exp[i] != '\0'){
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(&stack, exp[i]);
            count++;
        }

        else if(exp[i] == ')'){
            if(pop(&stack) == '(') count--;
            else break;
        }

        else if(exp[i] == '}'){
            if(pop(&stack) == '{') count--;
            else break;
        }

        else if(exp[i] == ']'){
            if(pop(&stack) == '[') count--;
            else break;
        }
        i++;
    }

    if(!count) printf("Expression is valid.\n");
    else printf("Expression is not valid\n");
}