/*
    * Searching an array for a target requires O(N) complexity.
    * If we have many targets (Q) the complexity increases to O(Q * N).
    * Hashing = Pre-storing + fetching.
    * We create a hash (frequency) array of size N, given N is the max number present in the array
      initialized with all zeros.
    * Frequencies of elements in the array are stored in the hash array at index = element. (pre-store + fetching)
    * hence for a 'target', frequency of times it appears is hash[target].
    * Maximum size of array = 10 ^ 6 (for int, inside int main())   = 10 ^ 7 (for boolean, inside int main())
    * Maximum size of array = 10 ^ 7 (for int, globally)    = 10 ^ 8 (for boolean, globally)
    * MAP STL:
        - map<key, value> : key is the array element, value is the frequency.
        - mpp[key]++ : assigns a (key, value) pair, with the value being incremented to 1 from 0.
        - In map, only the elements that are required are stored, keys with value = 0 are not stored.
        - mpp[value (not in array)] automatically assignes the value of key to 0.
        - map alwasy stores all keys in sorted order.
        - Storing and Fetching from map = O(logN) -> In all cases best, average, worst.
        - keys, value can be any datatype including stl types.
    * UNORDERED MAP STL:
        - keys are not stored in the sorted order.
        - storing, fetching = O(1) -> On average and best case.
                              O(N) -> On worst case (Due to internal collissions).
        - keys, value can only be standard datatypes.
    * NOTE: USE UNORDERED MAP, IF TLE (Time Limit Exceeded) THEN SWITCH TO MAP.
    * HOW DOES MAP DS WORK?
        - Division Method :
        - Folding Method :
        - Mod Square Method : 
*/
#include <bits/stdc++.h>
using namespace std;

int main(){

    // Hashing for integer arrays.
    int n = 5;
    int arr[] = {1, 3, 2, 1, 3};

    // Precomputing hash array.
    int hash[13] = {0};   // Assuming 'arr' has at max value '13'.
    for (int i = 0; i < n; i++)
        hash[arr[i]] += 1;  // Computing frequencies of each element in 'arr'.

    // Hashing for character arrays.
    string s = "abcdabehf";

    // Precomputing hash array.
    int hash_char[26] = {0};    // You can also take size of hash array as 256.
    for (int i = 0; i < s.length(); i++)
        hash_char[s[i] - 'a'] += 1;

    // Resolving query.
    cout << hash_char['a' - 'a'] << "\n";


    int n1 = 9;
    int arr1[] = {1, 2, 3, 5, 3, 1, 2, 10, 5};
    // Pre-computing hash map, coule be map<long long, ..> or similar depending on size required.
    unordered_map<int, int> mpp;
    for (int i = 0; i < n1; i++)
        mpp[arr1[i]]++;
    cout << mpp[11] << "\n";    // Resolving custom query.
    // Iterating through map.
    for(auto it : mpp)
        cout << it.first << "-->" << it.second << "\n";

    return 0;
}