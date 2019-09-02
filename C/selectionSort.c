#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("\n----------SELECTION SORT----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    int i,j,temp,min;
    //selection sort
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(array[j] < array[min])
                min = j;
        }
        //swap
        temp = array[i] + array[min];
        array[min] = temp - array[min];
        array[i] = temp - array[i];
    }
    
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("\n--------------EXIT--------------\n");
}