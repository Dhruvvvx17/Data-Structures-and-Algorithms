def linearSearch(array,key) -> int:
    n = len(array)

        if(array[i] == key):
            return i

    return -1

if __name__ == "__main__":
    print("\n------LINEAR SEARCH------\n")
    n = int(input("Enter array size: "))

    array = []

    print("Enter array elements: ")
    for i in range(n):
        ele = int(input())
        array.append(ele)

    key = int(input("Enter search element: "))

    position = linearSearch(array,key)

    if(position == -1):
        print("Element",key,"not found")
    else:
        print("element", key, "found at position", position)