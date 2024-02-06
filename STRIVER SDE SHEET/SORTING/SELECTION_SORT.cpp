/*
    * Selection Sort = Selections = We select the minimums and place in indexes starting from beginning.
    * On placing the minimum swap the places between the minimum and the element previously present.
    * This process ensures the first array position is sorted.
    * Repeat this process until all indexes are sorted.
    * TC = O(N ^ 2) -> Best, Worst and Average Time Complexity.
*/
#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int min_i = i;
        for (int j = i; j < n; j++)
            if(arr[j] < arr[min_i]) min_i = j;
        int temp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = temp;
    }
}

int main(){
    int n; // Size of the array.
    cin >> n;
    int arr[n]; // Input array.
    for (int i = 0; i < n; i++) cin >> arr[i];
    selection_sort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}