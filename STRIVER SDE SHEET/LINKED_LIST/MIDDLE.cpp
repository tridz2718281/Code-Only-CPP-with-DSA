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
            - 
*/

Node* middle(Node* head){
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