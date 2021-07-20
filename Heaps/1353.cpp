#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N=1e5+1;

class Comp
{
    public:
        bool operator()(int a,int b)
        {
            if(a<b)return false;
            else return true;
        }
};


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        
        priority_queue<int,vector<int>,greater<int>>pq; //Min priority queue
        vector<pii>a;
        
        for(int i=0;i<events.size();i++){
            a.pb(mp(events[i][0],events[i][1]));
        }
        sort(a.begin(),a.end());
        
        
        int ptr=0;
        int ans=0;
        int n=a.size();
        
        for(int i=1;i<N;i++)
        {
           
            
            //Push all the events
            while(ptr<a.size() && a[ptr].fi==i)
            {
                pq.push(a[ptr].se);
                ptr++;
            }
            
            if(pq.size()>0 && pq.top()>=i){
                pq.pop();ans++;
            }
            while(pq.size()>0 && pq.top()<=i){
                pq.pop();
            }
        }
        return ans;
    }
};


//////////////////////////// CODE USING SET & LOWERBOUND
class Compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second==b.second)return a.first<b.first;
        return a.second>b.second;
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>, vector<pair<int, int>>,Compare> pq;
        int maxi;
        for(int i=0; i<events.size(); i++){
            maxi = max(maxi,events[i][1]);
            pq.push(make_pair(events[i][0], events[i][1]));
        }
        
        int ans=0;
       // vector<bool> vis(100001, false);
        set<int> s;
        for(int i=1;i<=maxi;i++){
            s.insert(i);
        }
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            pq.pop();
            auto low = s.lower_bound(curr.first);
            if(low==s.end())continue;
            if((*low)<=curr.second){
                s.erase(*low);
                ans++;
            }
        }
        return ans;
    }
};
