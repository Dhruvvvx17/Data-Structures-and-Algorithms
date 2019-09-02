#include<stdio.h>
#include<ctype.h>
#define MAX 50

typedef struct stack{
    char a[MAX];
    char top;
}stack;

//function declarations
void init(stack *s);
void push(stack *s, char data);
void pop(stack *s, char *data);
int stackTop(stack *s);
int isEmpty(stack *s);
int precedence(char stackTop, char current);

void init(stack *s){
    s->top = -1;
}

void push(stack *s, char data){
    if(s->top == MAX-1){
        printf("Overflow.Increase array size to proceed.\n");
        return;
    }
    s->top++;
    s->a[s->top] = data;
    return;
}

void pop(stack *s,char *data){
    if(s->top == -1){
        printf("Underflow\n");
        return;
    }
    *data = s->a[s->top];
    s->top--;
    return;
}

int isEmpty(stack *s){
    return(s->top == -1);   //returns 1 if stack is empty, else 0.
}

int stackTop(stack *s){
    return(s->a[s->top]);
}

int precedence(char stackTop, char current){
    switch (current)
    // returning 1 means empty the stack then push the current operator
    // returning 0 means push the current operator
    {
    case '(':
        return 0;
        break;

    case ')':
        if(stackTop == '(') return 0;
        return 1;
        break;

    case '*':    //if stack top is + or - or ( then * or / is pushed above them 
    case '/':
        if(stackTop=='+' || stackTop=='-' || stackTop=='(') return 0;
        return 1;
        break;

    case '+':    //if stack top is + or - then new + or - are pushed above them 
    case '-':    //stack top is * or / then they are popped for current + or -   
        if(stackTop=='+' || stackTop=='-') return 0;
        else if(stackTop=='*' || stackTop=='/') return 1;
        return 0;
        break;                        
    }

    /*
    * or / above + or - => allowed |        a+b*c -- abc*+
    + or - above * or / => not allowed |    a*b+c -- ab*c+
    */
}

void main(){
    stack stack;
    init(&stack);
    char data;
    int i = 0, j = 0;
    char infix[50], postfix[50];
    printf("\nEnter the infix expression: ");
    scanf("%s",infix);

    while(infix[i] != '\0' ){
        if(isalnum(infix[i])) postfix[j++] = infix[i];
        else{
            while(!isEmpty(&stack) && precedence(stackTop(&stack),infix[i])){
                pop(&stack,&postfix[j++]);
            }
            if(infix[i]==')') pop(&stack,&data);
            else push(&stack,infix[i]);
        }
        i++;
    }
    
    while( !isEmpty(&stack)){
        pop(&stack,&postfix[j++]);
    }
    postfix[j] = '\0';
    printf("\npostfix expression: %s\n",postfix);    
}