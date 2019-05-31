#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int isLeaf;
    struct node *child[26]; //for the 26 english aplhabets
}node;

typedef struct trie{
    node *root;
    int words;
}trie;

node* getNode();
void insert(trie *trie,char *str);
void search(trie *trie,char *str);
int delete(node *curr,char *str);
int haveChildren(node *curr);

node* getNode(){
    node *temp = (node*)malloc(sizeof(node));
    temp->isLeaf = 0;
    for(int i=0;i<26;i++){
        temp->child[i] = '\0';
    }
    return temp;
}

void insert(trie *trie, char *str){
    char x[100];
    strcpy(x,str);
    node *curr = trie->root;
    while(*str){
        if(curr->child[*str - 'a'] == NULL)
            curr->child[*str - 'a'] = getNode();
        curr = curr->child[*str - 'a'];
        str++;
    }
    curr->isLeaf = 1;
    printf("\"%s\" successfully inserted\n",x);
    (trie->words)+=1;
    return;
}

void search(trie *trie, char *str){
    if(trie->root == NULL) {
        printf("Empty trie\n");
        return;
    }
    node *curr = trie->root;
    while(*str){
        curr = curr->child[*str - 'a'];
        if(curr == NULL) {
            printf("Not found\n");
            return;
        }
        str++;
    }
    if(curr->isLeaf)
        printf("Found\n");
    else
        printf("Not found\n");
    return;
}

void main(){
    trie trie;
    trie.root = (node*)malloc(sizeof(node));
    trie.root->isLeaf = 0;
    for(int i=0;i<26;i++){
        trie.root->child[i] = '\0';
    }
    trie.words = 0;
    int loop=1;
    int choice,data;
    char string[100]; //max string length is 100
    char *check;
    printf("\n\t------\n\t TRIE\n\t------\n");
    while(loop){
        printf("\n------------------\n1. Insert\n2. Search\n4. Number of words\n5. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        int d,v=1;
        switch(choice){

        case 1: //Insert
            printf("Enter the string: ");
            scanf("%s",string);
            check = string;
            while(*check && v){
                if (97 > *check || *check > 122){
                printf("Invalid character found. Use small case only.\n");
                v = 0;
                break;
                }
                check++;
            }
            if(v){
                insert(&trie, string);
            }
            break;

        case 2: //Search
            printf("Enter the string: ");
            scanf("%s",string);
            check = string;
            while(*check && v){
                if (97 > *check || *check > 122){
                printf("Invalid character found. Use small case only.\n");
                v = 0;
                break;
                }
                check++;
            }
            if(v){
                search(&trie, string);
            }
            break;

        case 4: //Number of words
            printf("Number of words in trie: %d\n",trie.words);
            break;

        case 5: //Exit
            free(trie.root);
            loop = 0;
            printf("-------EXIT-------\n");
            break;

        default:
            printf("Enter a valid option\n");
            break;   
        }
    } 
}