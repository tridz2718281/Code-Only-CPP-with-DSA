/*
    * Bubble Sort: Push the max to the last by adjacent swaps.
    * The final elements of the array gets sorted as we iterate through the outer loop.
    * 
*/
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){

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
