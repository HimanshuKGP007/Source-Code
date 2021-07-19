#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

set<string>s;
set<string>visited;

string source;
string dest;
int ans=INT_MAX;
void bfs()
{
    deque<pair<string,int>>dq;
    dq.pb(mp(source,0));
    visited.ins(source);
    
    while(dq.size()>0)
    {
        string top=dq.front().fi;
        //cout<<"THE STRING IS "<<top<<endl;
        int moves=dq.front().se;
        if(top.compare(dest)==0)
        {
            ans=moves;
            break;
        }
        dq.pop_front();
        
        
        for(int i=0;i<8;i++)
        {
            string a1,a2,a3,a4;
            a1=top;a2=top;a3=top;a4=top;
            a1[i]='A';
            a2[i]='C';
            a3[i]='G';
            a4[i]='T';
            auto itr1=visited.find(a1);
            auto it1=s.find(a1);
            if(top.compare(a1) && itr1==visited.end() && it1!=s.end())
            {
                visited.ins(a1);
                dq.pb(mp(a1,moves+1));
            }
            
            
            auto itr2=visited.find(a2);
            auto it2=s.find(a2);
            if(top.compare(a2) && itr2==visited.end() && it2!=s.end())
            {
                visited.ins(a2);
                dq.pb(mp(a2,moves+1));
            }
            
            auto itr3=visited.find(a3);
            auto it3=s.find(a3);
            if(top.compare(a3) && itr3==visited.end() && it3!=s.end())
            {
                visited.ins(a3);
                dq.pb(mp(a3,moves+1));
            }
            
            auto itr4=visited.find(a4);
            auto it4=s.find(a4);
            if(top.compare(a4) && itr4==visited.end() && it4!=s.end())
            {
                visited.ins(a4);
                dq.pb(mp(a4,moves+1));
            }
        }
    }
}

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        s.clear();
        visited.clear();
        
        for(int i=0;i<bank.size();i++)s.ins(bank[i]);
        
        
        source=start;
        dest=end;
        ans=INT_MAX;
        bfs();
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
