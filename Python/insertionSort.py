#Python program to perform insertion sort
def insertionSort(array):
    n = len(array)
    for i in range(n):
        c = array[i]
        j = i-1
        while(j>=0 and c < array[j]):
            array[j+1] = array[j]
            j = j-1
        array[j+1] = c

if __name__ == "__main__":
    print("\n------INSERTION SORT------\n")
    n = int(input("Enter array size: "))

    array = []

    print("Insert array elements: ")
    for i in range(n):
        ele = int(input())
        array.append(ele)

    insertionSort(array)

    print("Sorted array: ")
    print(array)