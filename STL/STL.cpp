/*
    https://youtu.be/RRVYpIET_RU?list=PLgUwDviBIf0p-INQC6rMuzsSmdZ77EcrH
    Standard Template Library (STL)
    -------------------------------
    * No need to predefine a container or algorithm alrady present in STL.
    * STL is a pre-compilation of Algorithms, Iterators, Functions, Containers etc.
    * STL : 1. Containers
            2. Functions
            3. Iterators
            4. Algorithms 
*/
#include<bits/stdc++.h> // All libraries like <math.h> and <string.h> are included.
using namespace std;    // No need to mention 'std::' while using library functions.  

// Function to explain the 'pair' container, lies in the 'utility' library.
void pairExplained(){
    pair<int, int> p = {1, 3}; // Datatype of elements in the pair are flexible.
    cout << p.first << " " << p.second;

    // Nested property of pair.
    pair<int, pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second;

    // Array of pairs, pair can be treated as a datatype.
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second;
}

/* 
    * Function to explain the 'vector' container.
    * Dynamic container, size adjusted dunamically.
    * Use when the size of list is not known beforehand.
    * Elements stored in contiguous memory locations.
    * Can be accessed using 'vec[int index]' or 'vec.at(int index)'.
*/
void vectorExplained(){
    // declaration, creates empty container.
    vector<int> v;

    // Pushing of values to vector.
    v.push_back(1);
    v.emplace_back(2);      // Faster than push-back()
    v.emplace_back(3);
    v.push_back(5);

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4); // Arguments automatically assumed as pair.

    vector<int> v1(5, 100); // Vector containing 5 instances of 100.
    vector<int> v2(5);      // vector containing 5 instances of 0.

    vector<int> v3(v2);     // creates copy of v2 into v3

    // Access vector with iterator.
    vector<int>::iterator it = v.begin(); // 'it' points to memory where vector begins.
    it += 2;                              // 'it' can be incremented to desired memory location.
    cout << *(it);                        // Element at address 'it' can be accessed.

    // Types of iterators.
    vector<int>::iterator it_end = v.end();                 // 'it_end' points to right after ending location.
    vector<int>::reverse_iterator it_rend = v.rend();       // 'it_rend' points to right before starting location.
    vector<int>::reverse_iterator it_rbegin = v.rbegin();   // 'it_rbegin' points to ending location, 'it++' moves
                                                            //  in reverse order

    cout << v.back() << " ";    // Output final element of v.

    // Traversing vector with iterator.
    for (vector<int>::iterator traverse = v.begin(); traverse != v.end(); traverse++){
        cout << *(traverse) << "\n"; 
    }
    // 'auto' automatically assigns it as a vector iterator according to data.
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    // For each loop, iterates through elements not memory location.
    for(auto it : v){
        cout << it << " ";
    }

}

// Driver code.
int main(){
    pairExplained();
    vectorExplained();
    return 0;
}