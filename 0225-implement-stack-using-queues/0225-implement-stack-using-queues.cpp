#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        
    }
    
    // Push element onto stack
    void push(int x) {
        q.push(x);
        
        // Rotate previous elements behind new element
        int size = q.size();
        for(int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes and returns top element
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    // Returns top element without removing
    int top() {
        return q.front();
    }
    
    // Returns true if stack is empty
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */