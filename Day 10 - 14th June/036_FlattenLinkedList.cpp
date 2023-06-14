/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node *mergeTwoSortedChildList(Node *head1,Node *head2){
	if(!head1 && !head2) return NULL;
	if(!head2 || (head1 && head1->data<head2->data)) {
		head1->child = mergeTwoSortedChildList(head1->child,head2);
		head1->next = NULL;
		return head1;
	}else{
		head2->child = mergeTwoSortedChildList(head1, head2->child);
		head2->next = NULL;
		return head2;
	}
}
Node* flattenLinkedList(Node* head) 
{	
	Node *temp1 = head;
	Node *temp2 = head->next;
	
	while(temp2){
		Node *next = temp2->next;
		temp1 = mergeTwoSortedChildList(temp1, temp2);
		temp2 = next;
	}
	return temp1;
}
