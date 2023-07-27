class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(isEmpty()) return -1;
        int output;
        if(!s2.empty()){
            output = s2.top();
            s2.pop();
        }
        else{
           while(s1.size()>1){
                int current = s1.top();
                s2.push(current);
                s1.pop();
            }
            output = s1.top();
            s1.pop();
        }
        return output;
    }

    int peek() {
        // Implement the peek() function here.
        if(isEmpty()) return -1;
        int output;
        if(!s2.empty()) return s2.top();
        else{
            while(s1.size()>1){
                int current = s1.top();
                s2.push(current);
                s1.pop();
            }
            output = s1.top();
            s2.push(s1.top());
            s1.pop();
        }
        return output;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};