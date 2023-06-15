#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
bool traverse(LinkedListNode<int> *forward,LinkedListNode<int> **backward){
    if(forward==NULL) return true;
    if(!traverse(forward->next,backward)) return false;
    if(forward->data!=(*backward)->data) return false;
    *backward = (*backward)->next;
    return true;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int> *backward = head;
    return traverse(head,&backward);
}