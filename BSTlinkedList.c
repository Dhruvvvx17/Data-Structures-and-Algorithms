#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

void createBST();
void preorder(node *r); 
void inorder(node *r);
void postorder(node *r);
node *delete(node *r, int ele);
void clear(node *r);

void createBST(node *r){
    node *temp, *p, *q;
    temp = (node*)malloc(sizeof(node));
    printf("Enter element: ");
    scanf("%d",&temp->data);
    temp->left = NULL;
    temp->right = NULL;

    q = NULL;
    p = r;
    if (p->data == temp->data){
        printf("Element already inserted.\n");
        free(temp);
        return;
    }
    //travers to the new element's parent
    while(p!=NULL && p->data != temp->data){
        q = p;
        if(temp->data < p->data)
            p = p->left;
        else
            p = p->right;
    }
    //insertion
    if(temp->data < q->data)
        q->left = temp;
    else
        q->right = temp;

    printf("Element %d inserted successfully\n",temp->data);
    return;
}

void preorder(node *r){
    if(r!= NULL){
        printf("%d ",r->data);
        preorder(r->right);
        preorder(r->left);
    }
    return;    
}

void inorder(node *r){
    if(r!= NULL){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
    return;
}

void postorder(node *r){
    if(r!= NULL){
        postorder(r->right);
        postorder(r->left);
        printf("%d ", r->data);
    }
    return;    
}

node* delete(node *r,int ele){
    node *temp , *p;
    if (r == NULL)  return r;
    
    if(ele < r->data)
        r->left = delete(r->left, ele);
    else if(ele > r->data)
        r->right = delete(r->right, ele);
    else{
        if(r->left == NULL){
            temp = r->right;
            free(r);
            return temp;
        }
        else if(r->right == NULL){
            temp = r->left;
            free(r);
            return temp;
        }
        else{
            p = r->right;
            while(p->left != NULL){
                p = p->left;
            }
            r->data = p->data;
            r->right = delete(r->right,p->data);
            return r;
        }
    }
    return r;
}

void clear(node *r){
    if(r->left != NULL){
        clear(r->left);
    }
    if(r->left != NULL){
        clear(r->right);
    }
    free(r);
    return;
}

void main()
{
    node *root;
    root = (node *)malloc(sizeof(node));
    printf("\n\t------------------\n\tBINARY SEARCH TREE\n\t------------------\n");
    printf("\nEnter the root element: ");
    scanf("%d", &root->data);
    root->left = NULL;
    root->right = NULL;
    int choice,ele,loop=1;
    while(loop){
        printf("\n----------------------------\n1. Insert\n2. Delete\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1://insert
                createBST(root);
                break;

            case 2://delete (does not handle the case of ele not present)
                printf("Enter element: ");
                scanf("%d",&ele);
                root = delete(root,ele);
                printf("Element deleted successfully\n");
                break;

            case 3://inorder
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4://preorder
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5://postorder
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6://exit
                clear(root);
                loop = 0;
                printf("--------------EXIT--------------\n");
                break;

            default:
                break;
        }
    }
}