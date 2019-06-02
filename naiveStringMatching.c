#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void firstOccurance(char *text, char *pattern);
void lastOccurance(char *text, char *pattern);
void numOccurance(char *text, char *pattern);

void firstOccurance(char *text, char *pattern){
    int n,m,i,j;
    n = strlen(text);
    m = strlen(pattern);
    for (i=0;i<=(n-m);i++){
        j = 0;
        while(j<m && (pattern[j] == text[i+j]))
            j+=1 ;
        if (j==m){
            printf("pattern \"%s\" found at position %d\n", pattern, i);
            return;
        }
    }
    printf("Pattern \"%s\" not found in the text.\n",pattern);
    return;
}

void lastOccurance(char *text, char *pattern){
    int n,m,i,j,k = 0;
    n = strlen(text);
    m = strlen(pattern);
    for (i=0;i<=(n-m);i++){
        j = 0;
        while(j<m && (pattern[j] == text[i+j]))
            j+=1;
        if (j==m)
            k=i;
    }
    if(k){
        printf("pattern \"%s\" found at position %d\n", pattern, k);
        return;
    }
    else
        printf("Pattern \"%s\" not found in the text.\n",pattern);
    return;
}

void numOccurance(char *text, char *pattern){
    int n,m,i,j,count = 0;
    n = strlen(text);
    m = strlen(pattern);
    for (i=0;i<=(n-m);i++){
        j = 0;
        while(j<m && (pattern[j] == text[i+j]))
            j+=1;
        if (j==m)
            count+=1;
    }
    printf("Number of occurances of pattern \"%s\" = %d\n", pattern, count);
    return;
}


void main(){
    char *text,*pattern;
    char temp[300];
    printf("\n\t-----------------\n\tNAIVE STRING MATCHING\n\t-----------------\n");
    printf("\nEnter Text: ");
    scanf("%[^\n]", temp);
    getchar();
    text = (char*)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(text,temp);
    printf("Enter Pattern: ");
    scanf("%[^\n]", temp);
    getchar();
    pattern = (char *)malloc(sizeof(char) * (strlen(temp)+1));
    strcpy(pattern,temp);

    int loop=1,choice;
    while(loop){
        printf("\n------------------\n1. First occurance\n2. Last occurance\n3. Number of occurances\n4. Enter new text\n5. Enter new Pattern\n6. Show Text and Pattern\n7. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){

        case 1: //first occurance
            firstOccurance(text,pattern);
            break;
        
        case 2: //last occurance
            lastOccurance(text,pattern);
            break;
        
        case 3: //number of occurances
            numOccurance(text,pattern);
            break;
        
        case 4: //Enter new text
            getchar();
            printf("\nEnter Text: ");
            scanf("%[^\n]", temp);
            text = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(text, temp);
            printf("Text successfully updated \n");
            break;

        case 5: //Enter new pattern
            getchar();
            printf("Enter Pattern: ");
            scanf("%[^\n]", temp);
            pattern = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(pattern, temp);
            printf("Pattern successfully updated \n");
            break;

        case 6:
            printf("Text: %s\n",text);
            printf("Pattern: %s\n",pattern);
            break;

        case 7: //exit
            free(text);
            free(pattern);
            printf("------------EXIT------------");
            loop = 0;
            break;

        default:
            printf("Please enter a valid option\n");
            break;
        }
    }
}