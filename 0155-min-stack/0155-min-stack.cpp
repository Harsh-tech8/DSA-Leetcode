

class MinStack {
private:
    std::stack<long long> s;
    long long minVal;

public:
    MinStack() {}
    
    void push(int val) {
        long long v = val;
        if (s.empty()) {
            minVal = v;
            s.push(v);
        } else if (v < minVal) {
            // Push encoded marker value
            s.push(2 * v - minVal);
            minVal = v; // Update current minimum
        } else {
            s.push(v);
        }
    }
    
    void pop() {
        if (s.empty()) return;
        
        long long topVal = s.top();
        s.pop();
        
        // If topVal < minVal, it was an encoded checkpoint
        if (topVal < minVal) {
            minVal = 2 * minVal - topVal; // Restore previous minVal
        }
    }
    
    int top() {
        long long topVal = s.top();
        if (topVal < minVal) {
            return (int)minVal; // Actual inserted value is stored in minVal
        }
        return (int)topVal;
    }
    
    int getMin() {
        return (int)minVal;
    }
};