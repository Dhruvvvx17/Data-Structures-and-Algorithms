#include<stdio.h>
#include<stdlib.h>

void main(){
    int n;
    printf("\n----------INSERTION SORT----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    int i,j,c;
    //insertion sort
    for(i=1;i<n;i++){
        c = array[i];
        j = i-1;
        while(j>=0 && c < array[j]){
            array[j + 1] = array[j];
            j-=1;
        }
        array[j+1] = c;
    }
    
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("\n--------------EXIT--------------\n");
}