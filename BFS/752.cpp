#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

set<string>s;
set<string>deadLocks;
string dest;
int moves=-1;

void bfs()
{
    string start="0000";
    auto it=deadLocks.find(start);
    if(it!=deadLocks.end())return;
    s.ins(start);
    deque<pair<string,int>>dq;
    dq.pb(mp(start,0));
    while(dq.size()>0)
    {
        string temp=dq.front().fi;
        int tot=dq.front().se;
        dq.pop_front();
       
        
        int x=dest.compare(temp);
        if(x==0)
        {
            moves=tot;
            break;
        }
        
        for(int i=0;i<4;i++)
        {
            int origDigit=temp[i]-'0';
            
            string check1=temp;
            string check2=temp;
                
            int newDigit1=(origDigit+1)%10;
            int newDigit2=(origDigit-1+10)%10;
            check1[i]=(newDigit1+'0');
            check2[i]=(newDigit2+'0');
               
            auto itr1=s.find(check1);
            auto itr2=deadLocks.find(check1);
            if(itr1==s.end() && itr2==deadLocks.end())
            {
                s.ins(check1);
                dq.pb(mp(check1,tot+1));
            }
                
            auto itr3=s.find(check2);
            auto itr4=deadLocks.find(check2);
            if(itr3==s.end() && itr4==deadLocks.end())
            {
                s.ins(check2);
                dq.pb(mp(check2,tot+1));
            }
                
        
        }
    }
}

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        s.clear();
        deadLocks.clear();
        
        
        for(int i=0;i<deadends.size();i++)
        {
            deadLocks.ins(deadends[i]);
        }
        dest=target;
        moves=-1;
        bfs();
        return moves;
    }
};
