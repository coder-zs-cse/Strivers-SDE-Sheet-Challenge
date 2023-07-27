#include<queue>
class Stack {
	// Define the data members.
    queue<int> q1,q2;
   public:
    Stack() {
        // Implement the Constructor.
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size()+q2.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(q1.size()==0 && q2.size()==0) return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        if(q1.empty()) q2.push(element);
        else q1.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty()) return -1;
        int output;
        if(q1.empty()){
            while(q2.size()>1){
                int current = q2.front();
                q1.push(current);
                q2.pop();
            }
            output = q2.front();
            q2.pop();
        }
        else if(q2.empty()){
            while(q1.size()>1){
                int current = q1.front();
                q2.push(current);
                q1.pop();
            }
            output = q1.front();
            q1.pop();
        }
        return output;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()) return -1;
        int output;
        if(q1.empty()){
            while(q2.size()>1){
                int current = q2.front();
                q1.push(current);
                q2.pop();
            }
            output = q2.front();
            q1.push(output);
            q2.pop();
        }
        else if(q2.empty()){
            while(q1.size()>1){
                int current = q1.front();
                q2.push(current);
                q1.pop();
            }
            output = q1.front();
            q2.push(output);
            q1.pop();
        }
        return output;

    }
};