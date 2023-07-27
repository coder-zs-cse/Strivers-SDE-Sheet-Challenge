#include <bits/stdc++.h> 
class Node{
    int data;
    Node *next;
    public:
    Node(int val){
        data = val;
        next  = NULL;
    }
    friend class Queue;
};
class Queue {
public:
    Node *head,*tail;
    Queue() {
        // Implement the Constructor
        head = NULL;
        tail = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return head==NULL;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        Node *newnode = new Node(data);
        if(isEmpty()) {
            tail = newnode;
            head = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        Node *temp = head;
        head = head->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return head->data;
    }
};