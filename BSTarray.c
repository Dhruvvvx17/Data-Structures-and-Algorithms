#include<stdio.h>
#include<stdlib.h>
#define NUM 5

typedef struct node{
    int data;
    int used;
}node;

typedef struct BST{
    node *root;
    int nodes;
    int size;
}BST;

void create(BST *bst);
void reallocate(BST *bst);
void inorder(BST *bst, int e);
void preorder(BST *bst, int e);
void postorder(BST *bst, int e);

void reallocate(BST *bst){
        bst->root = (node*)realloc(bst->root,2*(bst->size)*sizeof(node*));
        for(int i=bst->size;i<(2*bst->size);i++){
            bst->root[i].data = -1;
            bst->root[i].used = 0;
        }
        bst->size = 2 * bst->size;
}

void create(BST *bst){
    if ( bst->nodes == NUM ){
        reallocate(bst);
    }
    int ele,p=0;
    printf("Enter element: ");
    scanf("%d",&ele);

    while(p < NUM && bst->root[p].used){
        if (ele == bst->root[p].data){
            printf("Element exists\n");
            return;
        }
        else if(ele < bst->root[p].data )
            p = 2 * p + 1;
        else
            p = 2 * p + 2;    
    }

    if(p>NUM){
        reallocate(bst);
    }
    
    bst->root[p].data = ele;
    bst->root[p].used = 1;
    (bst->nodes)+=1;
    printf("%d inserted successfully\n",ele);
    return;
}

void inorder(BST *bst, int e){
    if(bst->root[e].used == 1){
        inorder(bst,2*e+1);
        printf("%d ",bst->root[e].data);
        inorder(bst,2*e+2);
    }
    return;
}

void preorder(BST *bst, int e){
    if(bst->root[e].used == 1){
        printf("%d ",bst->root[e].data);
        preorder(bst,2*e+1);
        preorder(bst,2*e+2);
    }
    return;
}

void postorder(BST *bst, int e){
    if(bst->root[e].used == 1){
        postorder(bst,2*e+1);
        postorder(bst,2*e+2);
        printf("%d ",bst->root[e].data);
    }
    return;
}

void main(){
    BST BST;
    int choice, ele, loop = 1;
    BST.root = (node*)malloc(sizeof(node)*NUM);
    BST.size = NUM;
    for(int i=0;i<NUM;i++){
        BST.root[i].data = -1;
        BST.root[i].used = 0;
    }
    printf("\n\t------------------\n\tBINARY SEARCH TREE\n\t------------------\n");
    printf("\nEnter the root element: ");
    scanf("%d", &ele);
    BST.root[0].data = ele;
    BST.root[0].used = 1;
    BST.nodes = 1; //root
    while(loop){
        printf("\n----------------------------\n1. Insert\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Number of nodes\n6. Exit\n7. Print array\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1://insert
                create(&BST);
                break;

            case 2://Inorder
                printf("Inorder: ");
                inorder(&BST,0);
                printf("\n");
                break;

            case 3: //Preorder
                printf("Preorder: ");
                preorder(&BST, 0);
                printf("\n");
                break;

            case 4: //postorder
                printf("Postorder: ");
                inorder(&BST, 0);
                printf("\n");
                break;

            case 5: //Number of nodes
                printf("Number of nodes: %d\n",BST.nodes);
                break;

            case 6: //exit
                free(BST.root);
                loop = 0;
                printf("--------------EXIT--------------\n");
                break;

            case 7: //print array
                for(int i=0;i<BST.size;i++){
                    printf("(%d , %d)", BST.root[i].data, BST.root[i].used);
                } 
                printf("\n");
                break;   

            default:
                printf("Enter valid option\n");
                break;
        }
    }
}