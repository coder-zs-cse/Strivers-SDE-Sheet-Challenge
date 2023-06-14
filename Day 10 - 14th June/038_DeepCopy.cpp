#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int> *,LinkedListNode<int> *> record;
    LinkedListNode<int> *temp  = head;
    LinkedListNode<int> *newhead = NULL;

    while(temp){
        LinkedListNode<int> *currentNode = new LinkedListNode<int>(temp->data);
        if(newhead==NULL) newhead = currentNode;
        record[temp] = currentNode;
        temp = temp->next;
    }
    temp = head;

    while(temp){
        record[temp]->next = record[temp->next];
        record[temp]->random = record[temp->random];
        temp = temp->next;
    }
    return newhead;

}
