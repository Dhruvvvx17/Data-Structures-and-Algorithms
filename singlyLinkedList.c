#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct list{
    node *head;
}list;

//function declarations
void init(list *l);
void insertBeginning(list *l,int data);
void insertEnd(list *l,int data);
void deleteBeginning(list *l);
void deleteEnd(list *l);
void insertAt(list *l,int data,int pos);
void deleteAt(list *l,int pos);
void reverse(list *l);
void disp(list *l);
void clear(list *l);

    void init(list *l)
{
    l->head = NULL;
}

void insertBeginning(list *l, int data){
    node *p;
    p = (node*)malloc(sizeof(node));
    if(p==NULL){
        printf("Inserting unsuccessful\n");
        return;
    }
    p->data = data;
    p->next = l->head;
    l->head = p;
    printf("%d Inserted successfully\n", data);
    return;
}

void insertEnd(list *l, int data){
    node *p,*q;
    p = (node*)malloc(sizeof(node));
    if(p==NULL){
        printf("Inserting unsuccessful\n");
        return;
    }
    p->data = data;
    p->next = NULL;
    q = l->head;
    if(q==NULL){
        l->head = p;
        printf("%d inserted successfully\n", data);
        return;
    }
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
    printf("%d inserted successfully\n", data);
    return;
}

void deleteBeginning(list *l){
    node *p,*q;
    p=l->head;
    if(p==NULL){
        printf("List is empty\n");
        return;
    }
    q=p->next;
    l->head = q;
    printf("%d deleted successfully\n",p->data);
    free(p);
    return;
}

void deleteEnd(list *l){
    node *p,*q;
    p=l->head;
    if(p==NULL){
        printf("List is empty\n");
        return;
    }
    q=p->next;
    if(q==NULL){
        l->head = NULL;
        printf("%d deleted successfully\n", p->data);
        free(p);
        return;
    }
    while(q->next != NULL){
        p=q;
        q = q->next;
    }
    p->next = NULL;
    printf("%d deleted successfully\n", q->data);
    free(q);
    return;
}

void insertAt(list *l, int data, int pos){
    if(pos < 1){
        printf("Invalid position\n");
        return;
    }
    int length = 0;
    node *p,*q,*r;
    r = (node*)malloc(sizeof(node));
    if (r == NULL){
        printf("Inserting unsuccessful\n");
        return;
    }
    r->data = data;
    p = l->head;
    while(p!=NULL){
        length++;
        p=p->next;
    }
    if(pos > length+1){
        printf("Invalid position\n");
        return;
    }
    p = l->head;
    if(pos == 1){
        r->next = p;
        l->head = r;
        printf("%d inserted successfully\n", data);
        return;
    }
    int i=1;
    while(i!=pos){
        q = p;
        p = p->next;
        i++;
    }
    q->next = r;
    r->next = p;
    printf("%d inserted successfully\n", data);
    return;
}

void deleteAt(list *l, int pos){
    if (pos < 1){
        printf("Invalid position\n");
        return;
    }
    if (l->head == NULL){
        printf("List is empty\n");
        return;
    }
    int length = 0;
    node *p, *q;
    p = l->head;
    while (p != NULL){
        length++;
        p = p->next;
    }
    if (pos > length){
        printf("Invalid position\n");
        return;
    }
    p = l->head;
    if (pos == 1){
        l->head = p->next;
        printf("%d deleted successfully\n",p->data);
        free(p);
        return;
    }
    int i=1;
    while (i != pos){
        q = p;
        p = p->next;
        i++;
    }
    q->next = p->next;
    printf("%d deleted successfully\n", p->data);
    free(p);
    return;
}

void reverse(list *l){
    if(l->head == NULL){
        printf("List is empty\n");
        return;
    }
    if(l->head->next == NULL){
        printf("List reversed\n");
        return;
    }
    node *p,*q,*r;
    r = l->head;
    q = r->next;
    p = q->next;
    r->next = NULL;
    while(p != NULL){
        q->next = r;
        r=q;
        q=p;
        p=p->next;
    }
    q->next = r;
    l->head = q;
    printf("List reversed\n");
}

void disp(list *l){
    if(l->head == NULL){
        printf("List is empty\n");
        return;
    }
    node *p = l->head;
    printf("List contains: ");
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

void clear(list *l){
    node *p,*q;
    p=l->head;
    while(p!=NULL){
        q = p;
        p = p->next;
        free(q);
    }
    l->head = NULL;
    printf("List cleared\n");
    return;
}

void main(){
    int loop=1;
    int choice,data,pos;
    list list;
    init(&list);
    printf("\n\t-------------------\n\tSINGLY LINKED LIST\n\t-------------------\n");
    while(loop){
        printf("\n----------------------------\n1. Insert in the beginning\n2. Insert in the end\n3. Delete from the beginning\n4. Delete from the end\n5. Insert at\n6. Delete at\n7. Reverse the list\n8. Display\n9. Clear\n10. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1: //insert beginning
                printf("Enter element: ");
                scanf("%d",&data);
                insertBeginning(&list,data);
                break;

            case 2: //insert end
                printf("Enter element: ");
                scanf("%d", &data);
                insertEnd(&list, data);
                break;
            
            case 3: //delete beginning
                deleteBeginning(&list);
                break;
            
            case 4: //delete end
                deleteEnd(&list);
                break;
            
            case 5: //insert at
                printf("Enter element: ");
                scanf("%d",&data);
                printf("Enter position: ");
                scanf("%d",&pos);
                insertAt(&list,data,pos);
                break;
            
            case 6: //delete at
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAt(&list,pos);
                break;
            
            case 7: //reverse
                reverse(&list);
                break;
            
            case 8: //display
                disp(&list);
                break;

            case 9: //clear
                clear(&list);
                break;

            case 10: //exit
                clear(&list);
                loop = 0;
                printf("------------EXIT------------\n");
                break;

            default:
                printf("Enter a valid option\n");
                break;        
                
        }
    }
}