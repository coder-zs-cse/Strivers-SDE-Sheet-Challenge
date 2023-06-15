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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *first = firstHead;
    Node *second = secondHead;
    while(first && second){
        first = first->next;
        second = second->next;
    }
    Node *firstHeadStart = firstHead;
    Node *secondHeadStart = secondHead;
    while(first){
        firstHeadStart = firstHeadStart->next;
        first = first->next;
    }
    while(second){
        secondHeadStart = secondHeadStart->next;
        second = second->next;
    }
    
    while(firstHeadStart && secondHeadStart){
        if(firstHeadStart==secondHeadStart) return firstHeadStart;
        firstHeadStart = firstHeadStart->next;
        secondHeadStart = secondHeadStart->next;
    }
    return NULL;
}