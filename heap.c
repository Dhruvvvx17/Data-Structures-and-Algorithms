#include<stdio.h>
#include<stdlib.h>
// MAX HEAP
void main(){
    int f,s,ele,n;
    printf("Enter number of elements to be inserted: ");
    scanf("%d",&n);
    int* heap;
    heap = (int*)malloc(sizeof(int)*n);
    printf("Enter heap elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&heap[i]);
    }

    //heapify - to convert array into max heap
    for(int i=1;i<n;i++){
        ele = heap[i];
        s = i;
        f = (s-1)/2;
        while(s>0 && heap[f]<ele){
            heap[s] = heap[f];
            s = f;
            f = (s-1)/2;
        }
        heap[s] = ele;
    }

    printf("Heap after heapifying: ");  //result after achiving a max-heap
    for(int i=0;i<n;i++)    printf("%d ",heap[i]);
    printf("\n");

    //readjust - to sort in acending order
    for(int i=n-1 ;i>0;i--){
        ele = heap[i];
        heap[i] = heap[0];
        f = 0;
        s = 1;

        if(i==1)    s = -1; //to check if current value is valid or not
        else
            if(i>2 && heap[s+1]>heap[s])    //to check if right sibling is greater than left
                s+=1;
        while( s>=0 && heap[s]>ele ){
            heap[f] = heap[s];
            f = s;
            s = 2*f+1;
            if(s>i-1)   s = -1; //to check if the iteration is still in bounds(within the heap size)
            else if(s+1 <= i-1 && heap[s+1]>heap[s])
                s+=1;   //to check if right sibling is greater than left
        }     
        heap[f] = ele;   //final array of size n-1 with greatest element as root
        // repeted until only 1 element is left
    }
    printf("Heap after readjusting: ");
    for(int i=0;i<n;i++)    printf("%d ",heap[i]);
    printf("\n");
}