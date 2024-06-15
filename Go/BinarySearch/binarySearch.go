package main

import "fmt"

func binarySearch(arr []int, ele int) int {
	var l int = 0
	var r int = len(arr) - 1

	for l <= r {
		var m int = l + (r-l)/2

		if (arr[m] == ele) {
			return m
		} else if (arr[m] < ele ) {
			l = m + 1
		} else {
			r = m - 1
		}
	}

	return -1
}

func main() {
	var n int;
	fmt.Print("Enter number of elements: ")
	fmt.Scan(&n)

	arr := make([]int, n)

	for i := 0; i<n; i++ {
		fmt.Print("Enter element ",i,": ")
		fmt.Scan(&arr[i])
	}

	fmt.Print("Array elements: ")
	for _, val := range arr {
		fmt.Print(val, " ")
	}
	fmt.Println()

	var ele int;
	fmt.Print("Enter element to search: ")
	fmt.Scan(&ele)

	pos := binarySearch(arr, ele)

	if pos < 0 {
		fmt.Println("Could not find element in array")
	} else {
		fmt.Printf("Element found at position %d\n", pos)
	}
}