/*
    * MERGE SORT: Uses divide and merge.
    * First divide the array to two equal parts, keep dividing until single element is encountered.
    * Then merge the single elements in sorted order (Use a two pointer system where each pointer is used
                                                      in the divided arrays)
    * low = starting point of hypothetical array, high = ending point of hypothetical array.
    * mid = (low + high) / 2
    * Base case = when low >= high.
*/
#include <bits/stdc++.h>
using namespace std;

// Remember to take everything in by reference.
void merge(vector<int> &arr, int low, int mid, int high){
    
}

void merge_sort(vector<int> &arr, int low, int high){
    if (low == high) return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}   

int main(){
    int n; // Size of the array.
    cin >> n;
    vector<int> arr(n); // Input array.
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}