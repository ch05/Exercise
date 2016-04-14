#include <iostream>
#include <queue> 

class Stack {
private:
    
    std::queue<int> first;
    std::queue<int> second;
    
    
public:
    // Push element x onto stack.
    void push(int x) {  //Assume we won't underflow or overflow according to stated assumption
        if((first.size() == 0 && second.size() == 0) || (first.size() > 0 && second.size() == 0)){  //Push to first queue by default, unless the first queue is empty while the second one is not
            first.push(x);    
        }
        else{   //Second queue is non-empty
            second.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {    //Assume we won't underflow, and we won't pop on an empty stack
        if(first.size() == 0){    //Pop the last item on the second queue
            for(int i = 0; i < (second.size()-1); i++){
                first.push(second.front());
                second.pop();
            }
            second.pop();
        }
        else{   //Pop the last item on the first queue otherwise
            for(int i = 0; i < (first.size()-1); i++){
                second.push(first.front());
                first.pop();
            }
            first.pop();
        }
    }

    // Get the top element.
    int top() { //Assume we won't underflow
               if(first.size() == 0){    //Pop the last item on the second queue
            for(int i = 0; i < (second.size()-1); i++){
                first.push(second.front());
                second.pop();
            }
            int topElement = second.front();
            first.push(second.front());
            return topElement;
        }
        else{   //Pop the last item on the first queue otherwise
            for(int i = 0; i < (first.size()-1); i++){
                second.push(first.front());
                first.pop();
            }
            int topElement = first.front();
            second.push(first.front());
            return topElement;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return(first.size() == 0 && second.size() ==0);
    }
};