#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
set<int>s;
vii answer;
int len,diff;

void bfs()
{
    deque<pii>dq; //Digit,Length
    for(int i=1;i<=9;i++)
    {
        dq.pb(mp(i,1));
    }
    while(dq.size()>0)
    {
        pii top=dq.front();
        dq.pop_front();
        int length=top.se;
        int num=top.fi;
        //cout<<"THE NUM AND LEN ARE "<<num<<":::"<<length<<endl;
        if(length==len)
        {
            auto itr=s.find(num);
            if(itr==s.end())
            {
                s.ins(num);
                answer.pb(num);
            }
        }
        
        if(length<len)
        {
            int lastDigit=num%10;
            int nxtDigit=lastDigit+diff;
            int nxtNum=num*10+nxtDigit;
            if(nxtDigit/10==0)dq.pb(mp(nxtNum,length+1));
        
            
            int nxtDigit2=lastDigit-diff;
            if(nxtDigit2>=0)
            {
                nxtNum=num*10+nxtDigit2;
                dq.pb(mp(nxtNum,length+1));
            }
        }
    }
}

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        s.clear();
        answer.clear();
        len=n;
        diff=k;
        bfs();
        return answer;
    }
};
