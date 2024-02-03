// SOURCE: https://youtu.be/wvcQg43_V8U?list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB
/*

    ALGORITHMS:
    -----------
    * Left rotate array by one place:
        1. OPTIMAL (Solving inside given array):
            - Left shift indexes 1 through n - 1
            - Push first element to 'n - 1' index. 
            - TC = O(N) - SC = O(N) --> In the entire algorithm.
                             = O(1) --> 'Extra Space' used by algorithm.

    * Left rotation of array by 'D' places: (Effectively D = D % N, Similar algorithm 
                                            for right shifting)
        1. BRUTE FORCE:
            - Store 'D' elements in a temporary array.
            - Shift the remaining 'D - N' elements left by 'D' places.
            - Put back the 'D' stored elements to end of array.
            - TC = O(N + d) - SC = O(d) --> We want to get rid of this extra space.
        2. OPTIMAL: (Obtained by observation)
            - Reverse first 'D' elements.
            - Reverse remaining 'N - D elements.
            - Reverse the entire array.
            - TC = O(N) - SC = O(1)

    * Moving zeroes to end of array.
        1. BRUTE FORCE:
            - Keep storing the non zero numbers to a different array.
            - Move the temporary array to the start of the original and replace remaining 
              elements to zero.
            - TC = O(2N) - SC = O(N) --> When no zero in the array.
        2. OPTIMAL:
            - Use 2 pointer approach.
            - Move non zero elements to pointer.
            - Increment the pointer.
            - Have edge case for no non zero numbers.
            - TC = O(N) - SC = O(1)

    * Linear Search.
        1. SOLUTION:
            - Iterate through array and return index where target is found.
            - TC = O(N) - SC = O(1)

    * Union of Two Sorted Arrays. (Must be sorted too hence dont use unordered list)
        1. BRUTE FORCE:
            - Use a set or a map and keep inserting from given arrays.
            - Store back in a vector.
            - TC = O(N1logN + N2logN) + O(N1 + N2) - SC = O(N1 + N2) + [O(N1 + N2)]
                                                                    To return answer. 

        2. OPTIMAL:
            - Use a 2 pointer approach, consider the union array must have unique elements.
            - 
*/

#include <bits/stdc++.h>
using namespace std;

void display_array(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void left_rotate(int arr[], int n, int d){

    // Using STL functions.
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

void move_zeros(int arr[], int n){
    int ptr = -1;

    for (int i = 0 ; i < n; i++){
        if (arr[i] == 0){
            ptr = i;
            break;
        }
    }

    if (ptr == -1)
        return;

    for (int j = ptr + 1; j < n; j++){
        if (arr[j] != 0){
            swap(arr[ptr], arr[j]);
            ptr++; 
        }
    }
}

int main(){

    int a[] = {1, 0, 2, 3, 0, 0, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);

    move_zeros(a, n);
    display_array(a, n);

    return 0;
}