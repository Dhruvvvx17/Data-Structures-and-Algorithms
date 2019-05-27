#include<stdio.h>
#include<stdlib.h>

typedef struct c_queue{
    int front;
    int rear;
    int capacity;
    int *queue_array;
}c_queue;

c_queue *init(int size);
void clear(c_queue *q);
int enqueue(c_queue *q, int data);
int dequeue(c_queue *q);
int empty(c_queue *q);
int full(c_queue *q);
void print(c_queue *q);

c_queue *init(int size){
    c_queue *temp = (c_queue*)malloc(sizeof(c_queue));
    temp->capacity = size;
    temp->front = -1;
    temp->rear = -1;
    temp->queue_array = (int*)malloc(sizeof(int)*size);
    return temp;
}

void clear(c_queue *q){
    free(q->queue_array);
    free(q);
}

int enqueue(c_queue *q, int data){
    if(full(q)) return 0;
    q->rear = (q->rear + 1)%(q->capacity);
    if(empty(q)) q->front = q->rear;
    q->queue_array[q->rear] = data;
    return 1;
}

int dequeue(c_queue *q){
    if(empty(q)) return 0;
    if(q->front == q->rear) q->front = -1;
    else q->front = (q->front + 1)%(q->capacity);
    return 1;
}

int empty(c_queue *q){
    return(q->front == -1); 
}

int full(c_queue *q){
    return((q->rear + 1)%(q->capacity) == (q->front));
}

void print(c_queue *q){
    if(empty(q)){
        printf("Empty queue\n");
        return;
    }
    int i = q->front;
    printf("%d ",q->queue_array[i]);
    i = (i+1)%(q->capacity);
    int j = (q->rear + 1)%(q->capacity);
    while(i!=j){
        printf("%d ", q->queue_array[i]);
        i = (i+1)%(q->capacity);
    }
    printf("\n");
}

void main()
{
    int loop=1;
    int choice,data,x;
    int size;
    printf("\n\t--------------\n\tCIRCULAR QUEUE\n\t--------------\n");
    printf("Enter queue size: ");
    scanf("%d",&size);
    c_queue *queue = init(size);
    while(loop){
        printf("\n----------------------------\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Enter element: ");
                scanf("%d",&data);
                x = enqueue(queue,data);
                if(x) printf("Enqueue successful\n");
                else printf("Queue is full\n");
                break;

            case 2:   
                x = dequeue(queue);
                if(x) printf("Dequeue successful\n");
                else printf("Empty Queue\n");
                break;  

            case 3:
                print(queue);
                break;

            case 4:
                loop = 0;
                clear(queue);
                printf("------------EXIT------------\n");
                break;

            default:
                printf("Enter valid option\n");    
        }
    }
}