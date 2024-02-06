/*
    * INSERTION SORT: Takes the element and places it in the correct position of the array.
    * TC = O(N ^ 2) -> worst and average case, = O(N) -> best case scenario.
*/
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
    for (int i = 0; i < n; i++){
        int j = i;
        // Swapping until the subarray from 0 to i is in the correct position.
        while (j > 0 && arr[j - 1] > arr[j]){
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}   

int main(){
    int n; // Size of the array.
    cin >> n;
    int arr[n]; // Input array.
    for (int i = 0; i < n; i++) cin >> arr[i];
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}