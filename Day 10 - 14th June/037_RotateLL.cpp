/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node *temp = head;
     int size = 0;
     while(temp){
          temp = temp->next;
          size++;
     }
     k%=size;
     if(k==0) return head;
     Node *newhead = NULL;
     Node *first = head;
     Node *second = head;
     while(k){
          second = second->next;
          k--;
     }
     Node *prev;
     while(second){
          prev = first;
          first = first->next;
          if(second->next==NULL) {
               second->next = head;
               break;
          }
          second = second->next;
     }
     prev->next = NULL;
     newhead = first;
     return newhead;

}