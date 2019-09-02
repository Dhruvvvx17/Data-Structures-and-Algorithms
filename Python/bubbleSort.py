#Python program to perform bubble sort
def bubbleSort(array):
    n = len(array)

    for i in range(n-1):
        noSwaps = True
        for j in range(0,n-i-1):
            if array[j] > array[j+1]:
                #Swap
                array[j],array[j+1] = array[j+1],array[j]
                noSwaps = False
        if noSwaps:
            break

if __name__ == "__main__":
    print("\n------BUBBLE SORT------\n")
    n = int(input("Enter array size: "))

    array = []

    print("Insert array elements: ")
    for i in range(n):
        ele = int(input())
        array.append(ele)

    bubbleSort(array)

    print("Sorted array: ")
    for i in range(n):
        print(array[i])