#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 50

typedef struct student{
    int rollno;
    char *usn;
    char *name;
    float cgpa;
}student;

typedef struct hashtable{
    student *array;
    int num;
}HT;

void init(HT *hashtable);
void read(student *s);
int hash_func(HT *hashtable,char *usn);
void insert(HT *hashtable, student *student,int index);
void search(HT *hashtable, char *usn,int index);

void init(HT *hashtable){
    hashtable->array = (student *)malloc(sizeof(student) * NUM);
    for (int i = 0; i < NUM; i++)
        hashtable->array[i].usn = NULL;
    hashtable->num = 0;
    return;
}

void read(student *s){
    char temp[200];
    printf("Enter roll no: ");
    scanf("%d",&s->rollno);
    printf("Enter Name: ");
    scanf("%s",temp);
    s->name = (char*)malloc(sizeof(char) * strlen(temp));
    strcpy(s->name,temp);
    printf("Enter USN: ");
    scanf("%s", temp);
    s->usn = (char *)malloc(sizeof(char) * strlen(temp));
    strcpy(s->usn, temp);
    printf("Enter cgpa: ");
    scanf("%f",&s->cgpa);
    printf("\n");
    return;
}

int hash_func(HT *hashtable,char *usn){
    usn = usn + 3;          //for usn format : PES1201700xxx
    return (atoi(usn) % NUM);
}

void insert(HT *hashtable, student *student, int index){
    if(hashtable->array[index].usn == NULL){
        hashtable->array[index].usn = (char *)malloc(sizeof(char) * strlen(student->usn));
        strcpy(hashtable->array[index].usn,student->usn);
        hashtable->array[index].rollno = student->rollno;
        hashtable->array[index].name = (char *)malloc(sizeof(char) * strlen(student->name));
        strcpy(hashtable->array[index].name, student->name);
        hashtable->array[index].cgpa = student->cgpa;
    }
    else{
        int j = (index + 1)%NUM;
        while(j!=index && hashtable->array[j].usn != NULL){
            j = (j+1) % NUM;
        }
        if(j == index){
            printf("Hash table full!\n");
            return;
        }
        else{
            hashtable->array[j].usn = (char *)malloc(sizeof(char) * strlen(student->usn));
            strcpy(hashtable->array[j].usn, student->usn);
            hashtable->array[j].rollno = student->rollno;
            hashtable->array[j].name = (char *)malloc(sizeof(char) * strlen(student->name));
            strcpy(hashtable->array[j].name, student->name);
            hashtable->array[j].cgpa = student->cgpa;
            index = j;
        } 
    }
    printf("Record inserted successfully at index: %d\n",index);
    (hashtable->num)+=1;
    return;
}

void search(HT *hashtable, char *usn, int index){
    if(hashtable->array[index].usn == NULL){
        printf("\n%s not present in the hash table\n",usn);
        return;
    }
    int show;
    if(! strcmp(hashtable->array[index].usn , usn)){
        printf("%s found at index %d\n",usn,index);
        printf("Show record (1/0)? ");
        scanf("%d",&show);
        if(show){
            printf("\nUSN: %s\n",hashtable->array[index].usn);
            printf("NAME: %s\n",hashtable->array[index].name);
            printf("ROLL NO: %d\n",hashtable->array[index].rollno);
            printf("CGPA: %f\n",hashtable->array[index].cgpa);
        }
        return;
    }
    int i = 1;
    int j = index + 1;
    while(j!=index && i){
        if(!strcmp(hashtable->array[j].usn , usn)){
            printf("%s found at index %d",usn,j);
            i = 0;
        }
        j = (j+1)%NUM;
    }
    if(j == index || i){
        printf("%s not present in the hash table\n",usn);
        return;
    }
    if(!i){
        printf("Show record (1/0)? ");
        scanf("%d",show);
        if(show){
            printf("USN: %s\n",hashtable->array[j].usn);
            printf("NAME: %s\n",hashtable->array[j].name);
            printf("ROLL NO: %d\n",hashtable->array[j].rollno);
            printf("CGPA: %d\n",hashtable->array[j].cgpa);
        }
        return;
    }
}

void main(){
    HT hashtable;
    student student;
    init(&hashtable);
    int loop = 1;
    int choice, data;
    printf("\n\t---------\n\t HASHING\n\t---------\n");
    while(loop){
        int index;
        char usn[30];
        printf("\n------------------\n1. Insert\n2. Search\n3. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){

        case 1: //insert
            read(&student);
            if(hashtable.num == NUM){
                printf("Hash table Full!\n");
                break;
            }
            index = hash_func(&hashtable,student.usn);
            insert(&hashtable,&student,index);
            break;

        case 2: //search
            if(hashtable.num == 0){
                printf("Hash table Empty!\n");
                break;
            }
            printf("Enter USN to search for: ");
            scanf("%s",usn);
            index = hash_func(&hashtable,usn);
            search(&hashtable,usn,index);
            break;

        case 3:
            loop = 0;
            free(hashtable.array);
            printf("-------EXIT-------\n");
            break;

        default:
            printf("Enter valid option\n");
            break;
        }
    }        
}