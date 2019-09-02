#include<stdio.h>
#include<stdlib.h>

void mergesort(int *array, int n);
void merge(int *array, int n, int m);
int binarySearch(int *array, int l, int r, int ele); //return index of first occurance of the element if present in the array.

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

int binarySearch(int *array, int l, int r, int ele){
    if(r-l+1 < 1)
        return -1;
    int m;
    m = (l+r)/2;
    if(ele == array[m])
        return m;
    else if(ele < array[m])
        return (binarySearch(array,l,m-1,ele));
    else
        return (binarySearch(array,m+1,r,ele));
}

void main(){
    int n;
    printf("\n----------BINARY SEARCH----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    mergesort(array, n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    int ele,l,r;
    int loop =1;
    do{
        printf("Enter Element to be searched: ");
        scanf("%d", &ele);
        l = 0;
        r = n;
        int index = binarySearch(array, l, r, ele);
        if (index != -1)
            printf("%d found at index %d\n", ele, index);
        else
            printf("%d not found in the array\n", ele);
        printf("Search for another element? (1/0) ");
        scanf("%d",&loop);
        printf("\n");
    }while(loop);
    printf("--------------EXIT--------------\n");
}