#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct priq{
    int *heap;
    int size;
    int nodes;
}priq;

void init(priq *q);
void reallocate(priq *q);
void enqueue(priq *q);
void dequeue(priq *q);
void print(priq *q);

void init(priq *q){
    q->heap = (int*)malloc(sizeof(int)*MAX);
    q->size = MAX;
    q->nodes = 0;
    return;
}

void reallocate(priq *q){
    q->heap = (int*)realloc(q->heap,sizeof(int)*2*(q->size));
    q->size = 2*(q->size);
    return;
}

void enqueue(priq *q){
    if(q->nodes == q->size) reallocate(q);
    int data;
    printf("Enter element: ");
    scanf("%d",&data);
    q->heap[q->nodes] = data;

    //heapify
    int s,f;    //son and father nodes
    s = q->nodes;
    f = (s-1)/2;
    while(s>0 && q->heap[f]<data){
        q->heap[s] = q->heap[f];
        s = f;
        f = (s-1)/2;
    }
    q->heap[s] = data;
    (q->nodes)+=1;
    printf("%d successfully enqueued\n",data);
    return;
}

void dequeue(priq *q){
    if(q->nodes == 0){
        printf("Empty queue\n");
        return;
    }
    int f,s,data,i;
    data = q->heap[q->nodes - 1];           // -----[1] last element of the heap
    q->heap[q->nodes] = q->heap[0];     //largest element is copied in place of the last element
    int high_pri = (q->heap[0]);    //currently the highest priority node to be dequeued.

    // find the right position for the last element of the heap from [1]
    // as well as convert into a max heap again.
    i = (q->nodes - 1);
    f = 0;
    s = 1;

    if (i == 1)
        s = -1;       //to check if current value is valid or not
    
    else if (i > 2 && q->heap[s + 1] > q->heap[s]) //to check if right sibling is greater than left
        s += 1;
    while (s >= 0 && q->heap[s] > data)
    {
        q->heap[f] = q->heap[s];
        f = s;
        s = 2 * f + 1;
        if (s > i - 1)
            s = -1; //to check if the iteration is still in bounds(within the heap size)
        else if (s + 1 <= i - 1 && q->heap[s + 1] > q->heap[s])
            s += 1; //to check if right sibling is greater than left
    }
    q->heap[f] = data; //final array of size n-1 with greatest element as root
    // repeted until only 1 element is left

    (q->nodes)-=1;
    printf("%d dequeued successfully\n",high_pri);
    return;
}

void print(priq *q){
    if(q->nodes == 0){
        printf("Empty queue\n");
        return;
    }
    printf("Queue contains: ");
    for(int i=0;i<(q->nodes);i++){
        printf("%d ",q->heap[i]);
    }
    printf("\n");
}

//Usually priority queues operate on a key-value node and the key is checked for priority.
//In this implementaion, the nodes value primarily indicates the priority.
//On every dequeue, the node with highest priority is removed and the remaining nodes are heapified again.
//A max heap approach ensures that the node with highest priority/value is always the root.

void main(){
    priq q;
    init(&q);
    printf("\n\t--------------\n\tPRIORITY QUEUE\n\t--------------\n");
    int choice, loop = 1;

    while (loop)
    {
        printf("\n----------------------------\n1. Enqueue\n2. Dequeue\n3. Print\n4. Number of nodes\n5. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1: //enqueue
            enqueue(&q);
            break;

        case 2: //dequeue
            dequeue(&q);
            break;

        case 3: //print
            print(&q);
            break;

        case 4: //number of nodes
            printf("Number of nodes: %d\n",q.nodes);
            break;

        case 5: //exit
            loop = 0;
            free(q.heap);
            printf("--------------EXIT--------------\n");
            break;            
        }
    }
}