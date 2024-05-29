#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int>input,output;

public:
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int x;
        if (output.empty()==false){
            x= output.top();
            output.pop();
            return x;
        }
        else {
            while (input.empty()==false) {
                output.push(input.top());
                input.pop();
            }

            x=output.top();
            output.pop();
            return x;
        }
    }
    
    int peek() {
        if (output.empty()==false){
            return output.top();
        }
        else {
            while (input.empty()==false){
                output.push(input.top());
                input.pop();
            }

            return output.top();
        }
        
    }
    
    bool empty() {
        if (input.empty()&&output.empty()){
            return true;
        }
        return false;
    }
};