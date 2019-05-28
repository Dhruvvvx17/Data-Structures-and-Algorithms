#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;


node* createBST();
void inorder(node *r);

node* createBST(){
    node *temp, *r, *p, *q;
    int wish;
    r = (node*)malloc(sizeof(node));
    printf("\nEnter the root element: ");
    scanf("%d",&r->data);
    r->left = NULL;
    r->right = NULL;
    do{
        temp = (node*)malloc(sizeof(node));
        printf("Enter element: ");
        scanf("%d",&temp->data);
        temp->left = NULL;
        temp->right = NULL;

        q = NULL;
        p = r;
        if (p->data == temp->data){
            printf("Duplicate\n");
            free(temp);
            break;
        }
        while(p!=NULL && p->data != temp->data){
            q = p;
            if(temp->data < p->data)    p = p->left;
            else    p = p->right;
        }
        if(temp->data < q->data)    q->left = temp;
        else    q->right = temp;

        printf("Add another node? (1/0): ");
        scanf("%d",&wish);
    }while(wish);
    return(r);
}

void inorder(node *r){
    if(r!= NULL){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
    return;
}

void main()
{
    node *root = NULL;
    root = createBST();
    inorder(root);
}