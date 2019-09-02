#include<stdio.h>
#include<stdlib.h>

void quicksort(int *array, int n);
int partition(int *array, int n);

void quicksort(int *array, int n){
    if(n<=1)
        return;
    int s = partition(array,n);
    quicksort(array,s);
    quicksort(array+s+1,n-s-1);
}

int partition(int *array, int n){
    int p,i,j,temp;
    p = array[0];
    i = 1;
    j = n-1;
    while(i<=j){
        while(i<=j && array[i] < p)
            i+=1;
        while(i<=j && array[j] > p)
            j-=1;
        
        if(i<j){
            //swap
            temp = array[i] + array[j];
            array[j] = temp - array[j];
            array[i] = temp - array[i];
            i+=1;
            j-=1;
        }
    }
    //swap
    temp = array[j] + array[0];
    array[j] = temp - array[j];
    array[0] = temp - array[0];
    return j;
}

void main(){
    int n;
    printf("\n----------QUICK SORT----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    quicksort(array,n);
    
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("\n--------------EXIT--------------\n");
}