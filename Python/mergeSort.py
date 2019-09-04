import math

def mergeSort(array):
    if(len(array)>1):
        m = len(array)//2
        L = array[:m]   #m not included
        R = array[m:]

        mergeSort(L)
        mergeSort(R)

        i=j=k=0

        while i < len(L) and j < len(R): 
            if L[i] < R[j]: 
                array[k] = L[i] 
                i+=1
            else: 
                array[k] = R[j] 
                j+=1
            k+=1
          
        # Checking if any element was left 
        while i < len(L): 
            array[k] = L[i] 
            i+=1
            k+=1
          
        while j < len(R): 
            array[k] = R[j] 
            j+=1
            k+=1


if __name__ == "__main__":
    print("\n------MERGE SORT------\n")
    n = int(input("Enter array size: "))

    array = []

    print("Insert array elements: ")
    for i in range(n):
        ele = int(input())
        array.append(ele)

    mergeSort(array)

    print("Sorted array: ")
    for i in range(n):
        print(array[i])