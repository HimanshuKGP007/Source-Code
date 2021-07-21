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
