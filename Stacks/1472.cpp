#define pb push_back
const int N=101;
vector<string>a;
int ptr;
int totalLength;
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        for(int i=0;i<N;i++)a.pb("hello");
        ptr=0;
        totalLength=0;
        a[0]=homepage;
    }
    
    void visit(string url) {
        ptr++;
        totalLength=ptr;
        a[ptr]=url;
    }
    
    string back(int steps) {
        ptr=max(0,ptr-steps);
        return a[ptr];
    }
    
    string forward(int steps) {
        ptr=min(ptr+steps,totalLength);
        return a[ptr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
