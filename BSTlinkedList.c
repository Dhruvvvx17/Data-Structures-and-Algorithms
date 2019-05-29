#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

typedef struct BST{
    node *root;
    int nodes;
}BST;

void createBST();
void preorder(node *root); 
void inorder(node *root);
void postorder(node *root);
node *delete(node *root, int ele, int *v);

void createBST(BST *bst){
    node *temp, *p, *q;
    temp = (node*)malloc(sizeof(node));
    printf("Enter element: ");
    scanf("%d",&temp->data);
    temp->left = NULL;
    temp->right = NULL;

    q = NULL;
    p = bst->root;
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
        else if (temp->data > p->data)
            p = p->right;
        else {
            printf("Element already inserted.\n");
            free(temp);
            return;
        }    
    }
    //insertion
    if(temp->data < q->data)
        q->left = temp;
    else
        q->right = temp;

    printf("Element %d inserted successfully\n",temp->data);
    (bst->nodes)+=1;
    return;
}

void preorder(node *root){
    if(root!= NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;    
}

void inorder(node *root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    return;
}

void postorder(node *root){
    if(root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    return;    
}

node* delete(node *root,int ele, int *v){
    node *temp , *p;
    if (root == NULL)  return root;
    
    if(root->left == NULL && root->right == NULL && root->data != ele){
        *v = 0;
        printf("Element is not present in the BST\n");
        return root;
    }
    else if((ele < root->data && root->left == NULL) || (ele > root->data && root->right == NULL) ){
        *v = 0;
        printf("Element is not present in the BST\n");
        return root;
    }

    if(ele < root->data)
        root->left = delete(root->left, ele, v);
    else if(ele > root->data)
        root->right = delete(root->right, ele, v);
    else{
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        else{
            p = root->right;
            while(p->left != NULL){
                p = p->left;
            }
            root->data = p->data;
            root->right = delete(root->right,p->data, v);
            return root;
        }
    }
    // *v = 1;
    return root;
}

void main()
{
    BST BST;
    BST.root = (node *)malloc(sizeof(node));
    BST.nodes = 1;  //root node
    printf("\n\t------------------\n\tBINARY SEARCH TREE\n\t------------------\n");
    printf("\nEnter the root element: ");
    scanf("%d", &BST.root->data);
    BST.root->left = NULL;
    BST.root->right = NULL;
    int choice,ele,loop=1, v;
    while(loop){
        printf("\n----------------------------\n1. Insert\n2. Delete\n3. Inorder traversal\n4. Preorder traversal\n5. Postorder traversal\n6. Number of nodes\n7. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1://insert
                if(BST.nodes == 0){
                    BST.root = (node *)malloc(sizeof(node));
                    printf("\nEnter the root element: ");
                    scanf("%d", &BST.root->data);
                    BST.root->left = NULL;
                    BST.root->right = NULL;
                    BST.nodes = 1; //root node
                }
                createBST(&BST);
                break;

            case 2://delete
                v=1;
                if(BST.nodes == 0){
                    printf("Empty BST\n");
                    break;
                }
                printf("Enter element: ");
                scanf("%d",&ele);
                BST.root = delete(BST.root,ele,&v);
                if(v){
                    printf("Element deleted successfully\n");
                    (BST.nodes) -= 1;
                }
                break;

            case 3://inorder
                if(BST.nodes == 0){
                    printf("Empty BST\n");
                    break;
                }
                printf("Inorder: ");
                inorder(BST.root);
                printf("\n");
                break;

            case 4://preorder
                if(BST.nodes == 0){
                    printf("Empty BST\n");
                    break;
                }
                printf("Preorder: ");
                preorder(BST.root);
                printf("\n");
                break;

            case 5://postorder
                if(BST.nodes == 0){
                    printf("Empty BST\n");
                    break;
                }
                printf("Postorder: ");
                postorder(BST.root);
                printf("\n");
                break;

            case 6://no of nodes
                printf("Number of nodes: %d\n",BST.nodes);
                break;

            case 7://exit
                free(BST.root);
                loop = 0;
                printf("--------------EXIT--------------\n");
                break;

            default:
                printf("Enter valid option\n");
                break;
        }
    }
}