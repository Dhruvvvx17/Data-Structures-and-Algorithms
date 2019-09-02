#include<stdio.h>
#include<stdlib.h>

void mergesort(int *array,int n);
void merge(int *array,int n,int m);

void mergesort(int *array, int n){
    if(n<=1)
        return;
    int m;
    m = n/2;
    mergesort(array,m);
    mergesort(array+m,n-m);
    merge(array,n,m);
}

void merge(int *array,int n,int m){
    int i=0,j=m,k=0;
    int *temp;
    temp = (int*)malloc(sizeof(int)*n);
    while(i<m && j<n){
        if(array[i] <= array[j]){
            temp[k] = array[i];
            i+=1;
        }
        else{
            temp[k] = array[j];
            j+=1;
        }
        k+=1;
    }
    if(j==n){
        while(i < m){
            temp[k] = array[i];
            k+=1;i+=1;
        }
    }
    else{
        while(j < n){
            temp[k] = array[j];
            k+=1;j+=1;
        }
    }

    for(int x=0;x<n;x++){
        array[x] = temp[x];
    }
    free(temp);
    return;
}

void main(){
    int n;
    printf("\n----------MERGE SORT----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    mergesort(array,n);
    
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("\n--------------EXIT--------------\n");
}