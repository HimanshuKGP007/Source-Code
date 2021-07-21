class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int ans=0;
        while(pq.size()>1)
        {
            int top1=pq.top();
            pq.pop();
            
            int top2=pq.top();
            pq.pop();
            
            top1--;top2--;
            if(top1>0)pq.push(top1);
            if(top2>0)pq.push(top2);
            
            ans++;
        }
        return ans;
    }
};

// Anshuman Solution O(1)

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        int ans=v[2];
        if(v[0]+v[1]>=v[2]){
            int extra=(v[0]+v[1]-v[2])/2;
            ans+=extra;
        }
        else{
            ans=v[0]+v[1];
        }
        return ans;
    }
};
