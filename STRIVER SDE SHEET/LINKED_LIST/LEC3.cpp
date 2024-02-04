// SOURCE: https://youtu.be/0eKMU10uEDI?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU
/*
    * 
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
        Node(int data, Node* next, Node* prev){
            this -> data = data;
            this -> next = next;
            this -> prev = prev;
        }
};


// Function converts a vector to a DLL.
Node<int>* vec2dll(vector<int> &vec){
    Node<int>* head = new Node<int>(vec[0]);
    Node<int>* prev = head;
    for (int i = 1; i < vec.size(); i++){
        Node<int>* temp = new Node<int>(vec[i], NULL, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

// Displays the DLL to console.
void display_dll(Node<int>* head){
    Node<int>* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node<int>* delete_head(Node<int>* head){

    if (head == NULL || head->next == NULL)
        return NULL;

    head = head->next;
    delete head->prev;
    head->prev->next = NULL;
    head->prev = NULL;
    return head;
}

Node<int>* delete_tail(Node<int>* head){

    if (head == NULL || head->next == NULL) return NULL;

    Node<int>* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    Node<int>* back = tail->prev;
    tail->prev = NULL;
    back->next = NULL;
    delete tail;
    return head;
}

Node<int>* delete_kth(Node<int>* head, int k){

    // Edge case for no elements.
    if(head == nullptr) return nullptr;

    int count = 0;
    Node<int>* kth = head;
    while(kth != nullptr){
        count++;
        if (count == k) break;
        kth = kth->next;
    }

    Node<int>* back = kth->prev;
    Node<int>* front = kth->next;

    // Edge case for single element.
    if (back == nullptr && front == nullptr) return nullptr;
    // Edge case for 
    else if (back == nullptr) return delete_head(head);
    // Edge case for deletion of tail.
    else if (front == nullptr)  delete_tail(head);

    back->next = front;
    front->prev = back;
    kth->next = nullptr;
    kth->prev = nullptr;
    delete kth;
    return head;
}

int main(){

    vector<int> v = {4, 5, 1, 2, 7, 8};

    Node<int>* head = vec2dll(v);
    display_dll(head);
    Node<int>* head_deleted = delete_head(head);
    display_dll(head_deleted);
    Node<int>* tail_deleted = delete_tail(head_deleted);
    display_dll(tail_deleted);
    Node<int>* kth_deleted = delete_kth(tail_deleted, 1);
    display_dll(kth_deleted);


    return 0;
}