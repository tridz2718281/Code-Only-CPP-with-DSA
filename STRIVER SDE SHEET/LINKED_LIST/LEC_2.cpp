/*
    * Deletion of head:
        - Move the head to the next element.
        - Free / Delete the initial head.
    * Deletion of tail:
        - Stop before the last element.
            for LL with 1 element, delete it.
        - Iterate through LL till second last element.
        - Delete the tail
        - Assign second last element -> next = NULL

    * Deletion of Kth element of list
        -  
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T> // Creates a flexible template datatype for LL. 

// Need to access Node object as Node<int>* obj.
class Node{

    public:
        T data;
        Node<T> *next;

        Node(){
            this -> data = 0;
            this -> next = NULL;
        }  

        Node(T data){
            this -> data = data;
            this -> next = NULL;
        }

        Node(T data, Node *next){
            this -> data = data;
            this -> next = next;
        }
};

Node<int>* cvt_arr2ll(vector<int> &arr){
    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* mover = head;     // Initially points to head, will traverse the array.

    for(int i = 1; i < arr.size(); i++){
        Node<int>* temp = new Node<int>(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;    // Only thing needed to traverse wntire LL.
}

void display_ll(Node<int>* head){
    Node<int>* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}

Node<int>* delete_head(Node<int>* head){

    // Edge case for empty LL.
    if (head == NULL)
        return head;

    Node<int>* temp = head -> next;
    free(head);
    head = temp; 
}

Node<int>* delete_tail(Node<int>* head){
    if (head == NULL || head -> next == NULL)
        return NULL;
    
    // Need to stop at second last element.
    Node<int>* temp = head;
    while (temp -> next -> next != NULL)
        temp = temp -> next;
    delete temp -> next;
    temp -> next = NULL;

    return head;
}

Node<int>* delete_kth(Node<int>* head, int k){

    // Handling edge cases.
    if (head == NULL) return NULL;
    if (k == 1){
        Node<int>* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    Node<int>* temp = head, *curr = NULL;
    int count = 1;
    while(temp){
        if (count == k){
            curr -> next = curr -> next -> next;
            delete temp;
            break;
        }
        count++;
        curr = temp;
        temp = temp -> next;
    }
    return head;
}

int main(){

    vector<int> vec = {4, 6, 3, 2, 1};
    Node<int>* head = cvt_arr2ll(vec);
    display_ll(head);
    head = delete_head(head);
    display_ll(head);
    head = delete_tail(head);
    display_ll(head);
    head = delete_kth(head, 3);
    display_ll(head);
    return 0;
}



