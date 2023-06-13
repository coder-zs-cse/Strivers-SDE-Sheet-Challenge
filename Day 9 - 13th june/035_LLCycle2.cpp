/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(!head || !head->next) return NULL;
    Node *slow = head->next;
    Node *fast = (head->next)->next;
    while(fast!=NULL && fast->next!=NULL && slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast==NULL || fast->next==NULL) return NULL;
    Node *late = head;
    while(late!=fast){
        late = late->next;
        fast = fast->next;
    }
    return late;
}