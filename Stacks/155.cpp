#define vii vector<int>
#define pb push_back
#define ins insert
const int N=3e4+1;
int ptr=-1;
vii a;
multiset<int>s;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        for(int i=0;i<N;i++)a.pb(0);
        s.clear();
        ptr=-1;
    }
    
    void push(int val) {
        ptr++;
        a[ptr]=val;
        s.ins(val);
    }
    
    void pop() {
        int val=a[ptr];
        ptr--;
        auto itr=s.find(val);
        s.erase(itr);
    }
    
    int top() {
        return a[ptr];
    }
    
    int getMin() {
        auto itr=s.begin();
        return *itr;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
