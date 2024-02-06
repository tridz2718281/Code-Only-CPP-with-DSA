/*
    * Bubble Sort: Push the max to the last by adjacent swaps.
    * The final elements of the array gets sorted as we iterate through the outer loop.
    * TC = O(N ^ 2) -> Worst and average complexity , O(N) -> Best case complexity, on
                                                      introducing some optimisations.
*/
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for (int i = n - 1; i >= 0; i--){
        bool did_swap = 0;
        for (int j = 0; j < i; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                did_swap = 1;
            }
            if (!did_swap)  break; // Breaks if no swap in first inner loop iteration,
                                   // indicationg already sorted array.
        }
    }    
}

int main(){
    int n; // Size of the array.
    cin >> n;
    int arr[n]; // Input array.
    for (int i = 0; i < n; i++) cin >> arr[i];
    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
