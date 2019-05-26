#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    char data;
    struct node *left;
    struct node *right;
}node;

typedef struct stack{
    node *s[50];
    int top;
}stack;

// function declarations
void push(stack *s,node *data);
node* pop(stack *s);
float eval(node *r);

void push(stack *s,node *data){
    if(s->top == 50){
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->s[s->top] = data;
    return;
}

node* pop(stack *s){
    return(s->s[s->top--]);
}

float eval(node *r){
float res;
switch(r->data){
    case '+':
        res = eval(r->left) + eval(r->right);
        break;
    case '-':
        res = eval(r->left) - eval(r->right);
        break;
    case '*':
        res = eval(r->left) * eval(r->right);
        break;
    case '/':
        res = eval(r->left) / eval(r->right);
        break;
    default:
        return (r->data - '0');
    }
    return res;
}

// works with postfix expressions only. Possible computation includes single digit numbers only.
void main(){
    node *root = NULL;
    stack stack;
    stack.top = -1;
    char postfix[50],ch;
    printf("Enter the postfix expression: \n");
    scanf("%s",postfix);
    int i=0;
    while(postfix[i]!='\0'){
        ch = postfix[i];
        node *temp = (node *)malloc(sizeof(node));
        temp->data = ch;
        if(isdigit(ch)){
            push(&stack,temp);
        }
        else{
            temp->right = pop(&stack);
            temp->left = pop(&stack);
            push(&stack,temp);
        }
        i++;
    }
    root = pop(&stack);
    printf("Answer: %f\n", eval(root));
}