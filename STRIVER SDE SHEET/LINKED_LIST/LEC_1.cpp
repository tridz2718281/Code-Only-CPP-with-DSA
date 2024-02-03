/*
    * Arrays are stored in contiguous location in heap memory, easy to traverse index wise but
      size cant be increased or decreased.
    * Linked List elements not in contiguous locations, but you can add extra elements readily into
      heap memory. or remove them from heap memory.
    * We store both data and next, from next we can find the next element from heap memory.
    * Tail of LL has next = nullptr
    * Need to keep a track of head to traverse LL, always points to first element of LL.
    * Never tamper the head otherwise we lose data.
    
    * Used in stack / queue. (Flexible in size)
    * Used in browsers. (2D LL Example)
    * 1D LL = only next pointer available, no prev available.
    
    * int x = 2, int* y = &x, cout << y (Creates x in heap memory somewhere, &x gives memory location of x
      which cannot be stored in a variable but y stores a pointer to it)
    * If stored variable is int then the pointer to it can only be stored by int*.

    * We define a self defined datatype Node.

    * Memory Space used:
        - for 32-Bit Systems -> int -> 4 bytes, * -> 4 bytes, total = 8 bytes.
        - for 64-Bit Systems -> int -> 4 bytes, * -> 8 bytes, total = 12 bytes.
        - Changes with class attributes.

    * Array to LL:
        - 

    * Searching element in Linked List:
        - TC = O(N) -> Worst Case, O(1) -> Best Case, O(N / 2) -> On Average. 
*/

#include <bits/stdc++.h>
using namespace std;


// Use a class instead of struct.
class Node {
    public:
        int data;
        Node* next;
    public:
        /*
            * You can make multiple constructors as different ways to initialize Node objects.
        */

        // Constructor.
        Node(int data1, Node* next1){
            data = data1;
            next = next1; 
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* cvt_arr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;     // Initially points to head, will traverse the array.

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;    // Only thing needed to traverse wntire LL.
}

void display_ll(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

int length_ll(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp -> next;
    }
    return count;
}

bool check_element_ll(Node* head, int target){
    Node* temp = head;
    while(temp){
        if (temp -> data == target)
            return 1;
        temp = temp -> next;
    }
    return 0;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};

    // Node y = new Node(arr[0], nullptr);  // new keyword can only be used for object pointers.
    // cout << y << "\n";   // Throws an error as object cannot be printed directly.

    Node y_test = Node(arr[0], nullptr);
    cout << y_test.data << "\n"; // Prints data attribute of y_test

    Node* y = new Node(arr[0], nullptr);
    cout << y -> data << "\n";  // Use this syntax to extract data from object y points to.

    vector<int> arr1 = {12, 5, 6, 7, 8};
    Node* cvt_ll = cvt_arr2ll(arr1);    // Stores head of new ll created.
    display_ll(cvt_ll);
    cout << length_ll(cvt_ll) << "\n";
    cout << check_element_ll(cvt_ll, 11) << "\n";
}