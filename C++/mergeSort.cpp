#include<iostream>
#include<vector>
using namespace std;

void merge(int start, int mid, int end, vector<int> &arr) {
    int i = start, j = mid + 1, k = 0;

    vector<int> temp(end - start + 1, 0);

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i += 1;
        } else {
            temp[k] = arr[j];
            j += 1;
        }
        k += 1;
    }


    while(i <= mid){
        temp[k] = arr[i];
        i += 1;
        k += 1;
    }

    while(j <= end){
        temp[k] = arr[j];
        j += 1;
        k += 1;
    }

    for(int x = start; x<=end; ++x){
        arr[x] = temp[x - start];
    }
    return;
}

void mergeSort(int start, int end, vector<int> &arr) {
    if(start >= end) return;

    int mid = (start + (end-start)/2);

    mergeSort(start, mid, arr);
    mergeSort(mid+1, end, arr);
    merge(start, mid, end, arr);
}

int main() {

    int n, ele;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n, 0);

    cout<<"Enter array values: \n";
    for(int i=0; i<n; ++i) {
        cin>>ele;
        arr[i] = ele;
    }

    cout<<"Initial array: ";
    for(int i=0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    mergeSort(0, n-1, arr);

    cout<<"Sorted array: ";
    for(int i=0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}