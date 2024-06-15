#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int element) {
    int l = 0;
    int r = arr.size() - 1;


    while(l <= r){
        int m = (l + (r-l)/2);

        if(arr[m] == element) return m;

        if (arr[m] < element) l = m + 1;

        else r = m - 1;
    }
    return -1;
}

int main() {

    vector<int> arr;
    int n;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements in sorted order"<<endl;
    int data;
    for(int i=0; i<n; i++){
        cout<<"Element "<<i<<": ";
        cin>>data;
        arr.push_back(data);
    }
    
    cout<<"Array elements: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int ele, pos;
    cout<<"Enter element to search: ";
    cin>>ele;

    pos = binarySearch(arr, ele);

    if(pos >= 0) cout<<"Found element at position "<<pos;

    else cout<<"Could not find element in array";

    return 0;
}