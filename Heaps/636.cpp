#define pb push
#define mp make_pair
#define fi first
#define se second
#define vii vector<int>
#define pii pair<int,int>
#define ins insert


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<pair<pii,int>>a;  // [id,time],  (1,-1)   (start,end)
        for(int i=0;i<logs.size();i++)
        {
            
            int id=0;
            int time=0;
            int op;
            
            int val=0;
            for(int j=0;j<logs[i].size();j++)
            {
                if(logs[i][j]>='0' && logs[i][j]<='9')
                {
                    if(val==0)id=id*10+(logs[i][j]-'0');
                    else time=time*10+(logs[i][j]-'0');
                }
                
                if(logs[i][j]==':' && val==0)
                {
                    val=1;
                    if(logs[i][j+1]=='s')op=1;
                    else op=-1;
                }
            }
            a.push_back(mp(mp(id,time),op));
           
            
        }
        
        
        stack<pair<pii,int>>s;
        vector<int>ans(n,0);
        
        for(int i=0;i<a.size();i++)
        {
            int id=a[i].fi.fi;
            int timeStamp=a[i].fi.se;
            int oper=a[i].se;
            
            
        
            if(s.size()==0)s.pb(mp(mp(id,timeStamp),oper));
            else
            {
                pair<pii,int>p=s.top();
                int stackId=p.fi.fi;
                int stackTime=p.fi.se;
                int stackOper=p.se;
                s.pop();
                
                if(oper==1)//START
                {
                    int val=timeStamp-stackTime;
                    ans[stackId]+=val;
                   
                    
                    s.pb(mp(mp(stackId,timeStamp),stackOper));
                    s.pb(mp(mp(id,timeStamp),oper));
                    
                }
                else
                {
                    ans[id]+=(timeStamp-stackTime+1);
                    if(s.size()>0)
                    {
                        stackId=s.top().fi.fi;
                        stackTime=s.top().fi.se;
                        stackOper=s.top().se;
                        s.pop();
                        timeStamp++;
                        s.pb(mp(mp(stackId,timeStamp),stackOper));
                        
                    }
                }
            }
        }
        
        
        return ans;
    }
};

// Anshuman Solution

class Solution {
public:
    void print_stk(stack<pair<int,int>> s){
        cout<<"Printing stack\n";
        while(!s.empty()){
            cout<<s.top().first<<" "<<s.top().second<<"\n";
            s.pop();
        }
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<pair<int,int>> process_stack;
        for(int i=0;i<logs.size();i++){
            int j=0;
            while(logs[i][j]!=':'){
                j++;
            }
            string pid=logs[i].substr(0,j);
            int k=j+1;
            while(logs[i][k]!=':'){
                k++;
            }
            string sOrE=logs[i].substr(j+1,k-j-1);
            string tim=logs[i].substr(k+1,logs[i].size()-1-k);
            stringstream stream1(pid);
            int proc_num=0;
            stream1>>proc_num;
            // cout<<proc_num<<" ";
            stringstream stream2(tim);
            int timestamp=0;
            stream2>>timestamp;
            // cout<<timestamp<<" ";
            // cout<<sOrE<<"\n";
            if(sOrE.compare("start")==0){
                if(process_stack.empty()){
                    process_stack.push(make_pair(proc_num,timestamp));
                }
                else{
                    ans[process_stack.top().first]+=timestamp-process_stack.top().second;
                    process_stack.push(make_pair(proc_num,timestamp));
                }
            }
            else if(sOrE.compare("end")==0){
                if(!process_stack.empty()){
                    ans[process_stack.top().first]+=timestamp-process_stack.top().second+1;
                    process_stack.pop();
                    if(!process_stack.empty())
                        process_stack.top().second=timestamp+1;
                }
            }
            //print_stk(process_stack);
        }
        return ans;
    }
};
