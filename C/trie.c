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
int search(trie *trie,char *str);
int delete(node **curr,char *str);
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

int search(trie *trie, char *str){
    char x[100];
    strcpy(x,str);
    if(trie->root == NULL) {
        printf("Empty trie\n");
        return 0;
    }
    node *curr = trie->root;
    while(*str){
        curr = curr->child[*str - 'a'];
        if(curr == NULL) {
            printf("\"%s\" Not found\n",x);
            return 0;
        }
        str++;
    }
    if(curr->isLeaf){
        printf("\"%s\" Found\n",x);
        return 1;
    }
    else{
        printf("\"%s\" Not found\n",x);
        return 0;
    }
}

int haveChildren(node* curr){
	for (int i = 0; i < 26; i++)
		if (curr->child[i])
			return 1;	// child found
	return 0;   //no child present
}

int delete(node **curr, char *str)
{
    // return if Trie is empty
    if (*curr == NULL)
        return 0;

    // if we have not reached the end of the string
    if (*str){
        // recur for the node corresponding to next character in the string and if it returns 1, delete current node (if it is non-leaf)
        if (*curr != NULL && (*curr)->child[*str - 'a'] != NULL && delete(&((*curr)->child[*str - 'a']), str + 1) && (*curr)->isLeaf == 0){
            if (!haveChildren(*curr)){
                free(*curr);
                (*curr) = NULL;
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    // if we have reached the end of the string
    if (*str == '\0' && (*curr)->isLeaf)
    {
        // if current node is a leaf node and don't have any children
        if (!haveChildren(*curr)){
            free(*curr); // delete current node
            (*curr) = NULL;
            return 1; // delete non-leaf parent nodes
        }
        // if current node is a leaf node and have children
        else{
            // mark current node as non-leaf node (DON'T DELETE IT)
            (*curr)->isLeaf = 0;
            return 0; // don't delete its parent nodes
        }
    }
    return 0;
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
        printf("\n------------------\n1. Insert\n2. Search\n3. Delete\n4. Number of words\n5. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        int s,d,v=1;    //search, delete, valid.
        switch(choice){

        case 1: //Insert
            printf("Enter the string: ");
            scanf("%s",string);
            check = string;
            while(*check && v){
                if (97 > *check || *check > 122){
                printf("Invalid string. Use small case only.\n");
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
                printf("Invalid string. Use small case only.\n");
                v = 0;
                break;
                }
                check++;
            }
            if(v){
                search(&trie, string);
            }
            break;

        case 3:
            printf("Enter the string: ");
            scanf("%s", string);
            check = string;
            while (*check && v){
                if (97 > *check || *check > 122){
                    printf("Invalid string. Use small case only.\n");
                    v = 0;
                    break;
                }
                check++;
            }
            if (v){
                s = search(&trie, string);
                if(s){
                    d = delete (&(trie.root), string);
                    if (d)
                        printf("Deleted\n");
                    else
                        printf("Occurance deleted, but cannot delete from trie as given string is a substring for a larger string\n");
                    (trie.words) -= 1;
                }
                else{
                    printf("Deletion unsuccessful.\n");
                }
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