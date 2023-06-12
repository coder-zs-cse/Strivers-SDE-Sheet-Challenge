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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *newHead, *prev = NULL, *current = head;
    while(current){
        LinkedListNode<int> *next = current->next;
        current->next = prev;
        prev  = current;
        current = next;
    }
    newHead = prev;
    return newHead;

}