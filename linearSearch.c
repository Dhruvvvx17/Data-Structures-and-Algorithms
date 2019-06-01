#include<stdio.h>

int search(int *a, int n, int ele); //return index of first occurance of the element if present in the array.
int search(int *a, int n, int ele){
    int j;
    j = 0;
    while(j < n){
        if(a[j] == ele)
            return j;
        j+=1;
    }
    return -1;    
}

void main(){
    int n;
    printf("\n----------LINEAR SEARCH----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int array[n];
    printf("Insert array elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int loop = 1,index,ele;
    do{
        printf("\nEnter element to be searched: ");
        scanf("%d", &ele);
        index = search(array,n,ele);
        if(index == -1) printf("%d not present in the array\n",ele);
        else printf("%d found at index %d\n",ele,index);
    
    printf("Search for another element? (1/0): ");
    scanf("%d",&loop);
    }while(loop);
    printf("--------------EXIT--------------\n");
}