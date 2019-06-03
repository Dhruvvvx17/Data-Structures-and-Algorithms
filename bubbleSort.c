#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("\n----------BUBBLE SORT----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    int i,j,temp;
    //bubble sort
    for(i=0;i<n-1;i++){
        int noSwaps = 1;
        for(j=0;j<n-1-i;j++){
            if(array[j] > array[j+1]){
                //swap
                temp = array[j+1] + array[j];
                array[j+1] = temp - array[j+1];
                array[j] = temp - array[j];
                noSwaps = 0;
            }
        }
        if (noSwaps)
            break;
    }

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("\n--------------EXIT--------------\n");
}