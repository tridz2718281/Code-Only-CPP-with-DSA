/*
    * Arrays are data structures that contain elements of same datatype, size is fixed.
    * int arr[6] defines array of int initialized with garbage values.
    * Maximum length of array inside int main() = 10 ^ 6, globally = 10 ^ 7.
    * Elements stored in contiguous memory locations.
*/

/*
    * Finding largest element of array:
        1. BRUTE FORCE:
            - Sort the array, last element is maximum.
            - TC = O(NlogN) - SC = O(1)
        2. BETTER:
            - Iterate through and find the largest element by successive comparison.
            - TC = O(N) - SC = O(1)

    * Finding second largest element of array:
        1. BRUTE FORCE:
            - Sort the array, last but one element is maximum.
            - If last two elements are same keep checking until non duplicate is found.
            - TC = O(NlogN + N) - SC = O(1)
        2. BETTER:
            - Iterate through and find the largest element by successive comparison.
            - Iterate through again and keep storing second largest element as less than 
              the largest but maximum among the other elements.
            - TC = O(2N) - SC = O(1)
        3. OPTIMAL:
            - Iterate through array elements, if current largest gets changed second largest 
              gets assigned to the current largest.
            - Dont do anything if current array iteration equal to largest.
            - Else if any element between largest and second largest update second largest.
            - TC = O(N) - SC = O(1)
    
    * Check if array is sorted:
        1. SOLUTION:
            - Break and return -1 if the gradient between successive elements < 0.
            - TC = O(N) - SC = O(1)
    
    * Remove duplicates in-place from sorted array: (First n elements should have n distinct 
                                                    elements, modifying given array.)
        1. BRUTE FORCE:
            - Initialize a Set.
            - Keep inserting elements of array into set. --> O(NlogN)
            - push elements of set into the array.       --> O(N)
            - TC = O(NlogN + N) - SC = O(N)
            NOTE: We dont care about the array after index 'n - 1'.

        2. OPTIMAL: (2 Pointer Approach)
            - Initialize pointer to first array element.
            - Find the next distinct element placing it to 'pointer + 1'
            - Keep repeating the process until end of array reached.
            - TC = O(N) - SC = O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int get_second_largest(vector<int> a, int n){
    int largest = a[0];
    int s_largest = -1;

    for(int i = 1; i < n; i++){
        if(a[i] > largest){
            s_largest = largest;
            largest = a[i];
        }
        else if(a[i] != largest && a[i] > s_largest)
            s_largest = a[i];
    }

    return s_largest;
}
int get_second_smallest(vector<int> a, int n){
    int smallest = a[0];
    int s_smallest = INT_MAX; // Since we are finding the smallest element we keep comparing with '<'.

    for(int i = 1 ; i < n; i++){
        if(a[i] < smallest){
            s_smallest = smallest;
            smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < s_smallest)
            s_smallest = a[i];
    }

    return s_smallest;
}

bool check_sorted(vector<int> a, int n){
    for(int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

vector<int> remove_duplicates(vector<int> a, int n){
    int ptr = 0;
    for (int i = 1; i < n; i++){
        if (a[i] != a[ptr])
            a[++ptr] = a[i];
    }
    return a;
    // NOTE: 'a' will have 'ptr + 1' uniue elements.
}

// Have proper variable and function naming.
pair<int, int> get_second_order_elements(vector<int> arr, int n){
    int s_largest = get_second_largest(arr, n);
    int s_smallest = get_second_smallest(arr, n);

    return {s_largest, s_smallest};
}

void display_vec(vector<int> a){
    for(auto it : a)
        cout << it << " ";
    cout << "\n";
}

int main(){
    vector<int> vec = {1, 1, 2, 3, 4, 4, 4, 5};
    int size = vec.size();

    cout << "Second Largest Element = " << get_second_order_elements(vec, size).first << "\n";
    cout << "Second Smallest Element = " << get_second_order_elements(vec, size).second << "\n";
    cout << "Is the Array Sorted? " << check_sorted(vec, size) << "\n";

    vector<int> vec1 = {1, 1, 2, 3, 3, 3, 4, 4, 2, 2};
    int size_vec1 = vec1.size();
    
    display_vec(remove_duplicates(vec1, size_vec1));

    return 0;
}