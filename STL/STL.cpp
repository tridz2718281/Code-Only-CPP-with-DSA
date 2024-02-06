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
        cout << *traverse << "\n"; 
    }
    // 'auto' automatically assigns it as a vector iterator according to data.
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    // For each loop, iterates through elements not memory location.
    for(auto it : v){
        cout << it << " ";
    }

    // Deletion in a vector.
    v.erase(v.begin() + 1); // Syntax : erase(iterator), deletes second element reshuffling vector.
    v.erase(v.begin() + 1, v.begin() + 3); // Syntax : erase(start, end), erases elements between start and end - 1.

    // Insertion in a vector.
    v.insert(v.begin(), 300); // Inserts 300 at the beginning.
    v.insert(v.begin() + 1, 2, 10); // 2 instances of 10 starting from beginning index + 1.
    vector<int> copy (2, 50);
    v.insert(v.begin(), copy.begin(), copy.end()); // Copy elements from 'copy' starting fron begin to end and insert to
                                                   // beginning of vector 'v'.
    cout << v.size() << "\n"; // Elements in the vector.
    v.pop_back(); // Pops out the last element.

    v1.swap(v2); // Swaps the two vectors.
    v.clear(); // Erases the entire vector to empty vector.
    cout << v.empty() << "\n"; // 1 -> if v is empty, 0 -> if v is not empty.
}

// List is same as vector but front operations are also available.
void listExplained(){
    list<int> ls;

    // Carries same meaning as operations in list.
    ls.push_back(2);
    ls.emplace_back(4);

    // Pushing values to front of list, insert in a vector is costlier.
    ls.push_front(5);
    ls.emplace_front(8);

    // Rest functions and iterators are same as in vectors.
}

void dequeExplained(){
    deque<int> dq;

    // Placing values to front and back.
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);

    // Popping elements from both front and back.
    dq.pop_back();
    dq.pop_front();

    // Accessing front and back elements.
    dq.back();
    dq.front();

    // Rest functions and iterators are same as in vectors.
}

// Stack follows LIFO = Last In First Out, all operations cost O(1).
void stackExplained(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);

    cout << st.top() << "\n"; // st[2] is invalid, returns element that was pushed last.

    st.pop(); // Pops the top element.

    cout << st.size() << "\n";
    cout << st.empty() << "\n"; // 1 -> if st is empty, 0 -> if st is not empty.

    stack<int> st1, st2;
    st1.swap(st2); // Swaps two stacks.
}

// Queue follows FIFO = Last In First Out, all operations cost O(1).
void queueExplained(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);

    q.back() += 5; // q.back() is the element last pushed onto queue.
    q.front() += 4; // 1.front() is the beginning element of the queue.

    q.pop(); // Pops the element at the front.

    // size, swap, empty same as stack.
}

void PQexplained(){
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.emplace(3);
}

// Driver code.
int main(){
    pairExplained();
    vectorExplained();
    listExplained();
    dequeExplained();
    stackExplained();
    return 0;
}