package main

import "fmt"

func merge(start int, mid int, end int, arr []int) {
	i := start
	j := mid + 1
	k := 0

	temp := make([]int, end - start + 1)

	for i <= mid && j <= end {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i]
			i += 1
		} else {
			temp[k] = arr[j]
			j += 1
		}
		k += 1
	}

	for i <= mid {
		temp[k] = arr[i]
		i += 1
		k += 1
	}

	for j <= end {
		temp[k] = arr[j]
		j += 1
		k += 1
	}

	for x := start; x <= end; x++ {
		arr[x] = temp[x - start]
	}
	return
}

func mergeSort(start int, end int, arr []int) {
	if (start >= end){
		return
	}

	var mid int = start + (end - start)/2

	mergeSort(start, mid, arr)
	mergeSort(mid + 1, end, arr)
	merge(start, mid, end, arr)
	return
}

func main(){
	var n int
	fmt.Print("Enter number of elements: ")
	fmt.Scan(&n)

	arr := make([]int, n)

	fmt.Print("Enter array elements: ")
	for i:=0; i<n; i++ {
		fmt.Scan(&arr[i])
	}


	fmt.Print("Initial Array: ")
	for i:=0; i<n; i++ {
		fmt.Print(arr[i]," ")
	}
	fmt.Println()

	mergeSort(0, n-1, arr)

	fmt.Print("Sorted Array: ")
	for i:=0; i<n; i++ {
		fmt.Print(arr[i]," ")
	}
	fmt.Println()
}