/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *temp1 = num1;
    Node *temp2 = num2;
    Node *head = NULL;
    Node *temp = NULL;
    int carry = 0;
    while(temp1 || temp2){
        int currentVal = carry + (temp1 ? temp1->data : 0 )+ (temp2 ? temp2->data : 0);
        carry = currentVal/10;
        currentVal%=10;
        Node *current = new Node(currentVal);
        if(temp) temp->next = current;
        else head = temp = current;
        temp = current;
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }

    while(carry){
        Node *current = new Node(carry%10);
        carry/=10;
        temp->next = current;
        temp = current;
    }
    return head;
}
