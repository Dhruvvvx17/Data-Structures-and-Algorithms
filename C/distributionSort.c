#include<stdio.h>
#include<stdlib.h>
//Works well for an array with numbers within a limit. Eg array of size containing numbers b/w 1 and 5 only.
void main(){
    int n;
    printf("\n----------DISTRIBUTION COUNTING SORT----------\n\n");
    printf("Enter array size: ");
    scanf("%d",&n);
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    printf("Insert array elements: ");

    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    int i,j,u,l,temp;
    int *freq,*sorted;
    sorted = (int*)malloc(sizeof(int)*n);

    //distribution counting sort
    //find upper & lower limit
    l = array[0];
    u = array[0];

    for(i=1;i<n;i++){
        if(array[i] < l)
            l = array[i];
        if(array[i] > u)
            u = array[i];
    }
    printf("lower limit: %d ",l);
    printf("upper limit: %d\n",u);
    freq = (int *)malloc(sizeof(int) * (u-l+1));
    //initialize all frequencies to 0
    for(j=0;j<(u-l+1);j++)
        freq[j] = 0;
    //increment frequencies
    for(j=0;j<n;j++)
        freq[array[j]-l] = freq[array[j]-l] + 1;
    //find cummulative frequency
    for(j=1;j<(u-l+1);j++)
        freq[j] = freq[j-1]+freq[j];

    //sort
    for(i=n-1;i>=0;i--){
        j = array[i] - l;                   //corresponding element in freq array
        sorted[freq[j] - 1] = array[i];     //final position of element in sorted array
        freq[j] = freq[j] - 1;              //reduce frequency of element by 1
    }

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",sorted[i]);
    }
    printf("\n");
    printf("\n---------------------EXIT---------------------\n");
}