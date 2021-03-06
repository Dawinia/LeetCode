class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int size;

public:
    CQueue() {
        size = 0;
    }
    
    void appendTail(int value) {
        s1.push(value);
        ++size;
    }
    
    int deleteHead() {
        if(size == 0)
            return -1;
        int i = size;
        while(i > 1) {
            s2.push(s1.top());
            s1.pop();
            --i;
        }
        int val = s1.top();
        s1.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        --size;
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */