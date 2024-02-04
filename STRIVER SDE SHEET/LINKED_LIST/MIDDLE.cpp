#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

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
/*
    * Return the middle node of a given LL of size N.
        1. BRUTE FORCE: (Two pass solution)
            - TC = O(N + N / 2) - SC = O(1)

        2. OPTIMAL: (Tortoise and Hare ALgorithm)
            - Move slow pointer by 1 step, fast pointer by 2 steps simultaneously.
            - Moment fast pointer reaches tail (for N = Odd) or NULL (for N = Even), slow points to mid node.
            - LOGIC: P1 moves with speed x, P2 with speed x/2 hence the distance covered by P2 will be half
                     of the total distance in the LL.
            - TC = O(N / 2) - SC = O(1)
*/

Node* middle_BRUTE(Node* head){
    Node* itr = head;
    int len = 0;
    while (itr != nullptr){
        len++;
        itr = itr->next;
    }
    int mid = ( len / 2 ) + 1;
    itr = head;
    while (mid > 0){
        itr = itr->next;
    }
    return itr;
}

Node* middle_OPTIMAL(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}