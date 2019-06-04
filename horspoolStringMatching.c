#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int firstOccurance(char *text,int n,char *pattern,int m,int *shiftTable);
int lastOccurance(char *text,int n,char *pattern,int m,int *shiftTable);
int numOccurance(char *text,int n,char *pattern,int m,int *shiftTable);

int firstOccurance(char *text,int n,char *pattern,int m,int *shiftTable){
    int i,j;
    i = m - 1;
    while (i < n)
    {
        j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j])
            j += 1;

        if (j == m)
            return i-(m-1);
        i = i + shiftTable[text[i]];
    }
    return -1;
}

int lastOccurance(char *text, int n, char *pattern, int m, int *shiftTable){
    int i, j, k=-1;
    i = m - 1;
    while (i < n)
    {
        j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j])
            j += 1;

        if (j == m)
            k = i-(m-1);
        i = i + shiftTable[text[i]];
    }
    return k;
}

int numOccurance(char *text, int n, char *pattern, int m, int *shiftTable){
    int i, j, c=0;
    i = m - 1;
    while (i < n)
    {
        j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j])
            j += 1;

        if (j == m)
            c+=1;
        i = i + shiftTable[text[i]];
    }
    return c;
}

void main(){
    char *text,*pattern;
    char temp[300];
    printf("\n\t---------------------\n\tNAIVE STRING MATCHING\n\t---------------------\n");
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
    int m = strlen(pattern);
    int n = strlen(text);
    int *shiftTable;
    shiftTable = (int*)malloc(sizeof(int)*256); //value for 256 ascii characters

    for(int i=0;i<256;i++)
        shiftTable[i] = m;
    
    for(int j=0;j<m-1;j++)
        shiftTable[pattern[j]] = m-1-j;

    int loop=1,choice,index,count;
    while(loop){
        printf("\n------------------\n1. First occurance\n2. Last occurance\n3. Number of occurances\n4. Enter new text\n5. Enter new Pattern\n6. Show Text and Pattern\n7. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){

        case 1: //first occurance
            index = firstOccurance(text, n, pattern, m, shiftTable);
            if (index == -1)
                printf("Pattern \"%s\" not found in the text.\n", pattern);
            else
                printf("First occurance of pattern \"%s\" found at position %d\n", pattern, index);
            break;
        
        case 2: //last occurance
            index = lastOccurance(text, n, pattern, m, shiftTable);
            if (index == -1)
                printf("Pattern \"%s\" not found in the text.\n", pattern);
            else
                printf("Last occurance of pattern \"%s\" found at position %d\n", pattern, index);
            break;
        
        case 3: //number of occurances
            count = numOccurance(text, n, pattern, m, shiftTable);
            printf("Number of occurances of pattern \"%s\" = %d\n", pattern, count);
            break;
        
        case 4: //Enter new text
            getchar();
            printf("\nEnter Text: ");
            scanf("%[^\n]", temp);
            text = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(text, temp);
            n = strlen(text);
            printf("Text successfully updated \n");
            break;

        case 5: //Enter new pattern
            getchar();
            printf("Enter Pattern: ");
            scanf("%[^\n]", temp);
            pattern = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(pattern, temp);

            for (int i = 0; i < 256; i++)
                shiftTable[i] = m;

            for (int j = 0; j < m - 1; j++)
                shiftTable[pattern[j]] = m - 1 - j;
            m = strlen(pattern);
            printf("Pattern and shift table successfully updated \n");
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