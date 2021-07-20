#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

set<string>s;
int add;
int rot;
string mainStr;
string finalAns;

void bfs()
{
    deque<string>dq;
    dq.pb(mainStr);
    s.ins(mainStr);
    while(dq.size()>0)
    {
        string topStr=dq.front();
        dq.pop_front();
        
        
        int x=topStr.compare(finalAns);
        if(x<0)finalAns=topStr;
        
        string topStr1=topStr;
        for(int i=0;i<topStr1.size();i++)
        {
            if(i%2==1)
            {
                int x=topStr1[i]-'0';
                x+=add;
                x%=10;
                topStr1[i]=x+'0';
            }
        }
        
        auto itr1=s.find(topStr1);
        if(itr1==s.end()){
            dq.pb(topStr1);
            s.ins(topStr1);
        }
        
        
        
        string topStr2;
        int n=topStr.size();
        for(int i=n-rot;i<n;i++)topStr2+=topStr[i];
        for(int i=0;i<n-rot;i++)topStr2+=topStr[i];
        
        auto itr2=s.find(topStr2);
        if(itr2==s.end()){
            dq.pb(topStr2);
            s.ins(topStr2);
        }
    }
}
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        mainStr=s;
        finalAns=s;
        add=a;
        rot=b;
        s.clear();
        bfs();
        return finalAns;
    }
};
