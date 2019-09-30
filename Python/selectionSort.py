#Python program to perform selection sort
def selectionSort(array):
    n = len(array)

    for i in range(n-1):
        min = i
        for j in range(i+1,n):
            if(array[j] < array[min]):
                min = j
        array[i],array[min] = array[min],array[i]


if __name__ == "__main__":
    print("\n------SELECTION SORT------\n")
    n = int(input("Enter array size: "))

    array = []

    print("Insert array elements: ")
    for i in range(n):
        ele = int(input())
        array.append(ele)

    selectionSort(array)

    print("Sorted array: ")
    print(array)