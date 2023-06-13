#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[],int counter=1,int index=0){
	// Write your code here.
	if(!head) return head;
	while(counter>b[index]) {
		counter = 1;
		index++;
	}
	if(index>=n) return head;
	head->next = getListAfterReverseOperation(head->next,n,b,counter+1,index);
	
	if(counter==1){
		Node *newHead = NULL;
		Node *temp = head,*prev = NULL;
		int count = b[index];
		if(count==1) return head;
		while(count){
			if(!temp) break;
			Node *next = temp->next;
			temp->next = prev;
			prev = temp;
			temp = next;
			count--;
		}
		newHead = prev;
		head->next = temp;
		return newHead;
	}
	return head;
}