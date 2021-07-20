#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N=21*21;

vector<bool>check(N,false);
map<int,int>m;

int target;
int reach=0;
int answer=0;

void bfs(int start)
{
    deque<pii>q;
    q.push_front(mp(start,0));

    check[start]=true;
    
    while(q.size()>0)
    {
        int u=q.front().fi;
        int len=q.front().se;
        
        q.pop_front();
        if(u==target)
        {
            reach=1;
            answer=len;
            break;
        }
        
        for(int i=1;i<=6;i++)
        {
            int v=u+i;
            if(v>target)break;
            auto itr=m.find(v);
            if(itr!=m.end())v=itr->se;
            
            if(check[v]==false){
                check[v]=true;
                q.pb(mp(v,len+1));
                if(v==target){
                    answer=len+1;break;
                }
            }
        }
    }
}

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n=board.size();
        m.clear();
        
        int ptr=0;
        reach=0;
        int opp=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(opp==0)
            {
                for(int j=0;j<board[i].size();j++)
                {
                    if(board[i][j]!=-1)
                    {
                        board[i][j]--;
                        m[ptr]=board[i][j];
                    }
                    ptr++;
                }
                opp=1;
            }
            else if(opp==1)
            {
                int sizes=board[i].size();
                for(int j=sizes-1;j>=0;j--)
                {
                    if(board[i][j]!=-1)
                    {
                        board[i][j]--;
                        m[ptr]=board[i][j];
                    }
                    ptr++;
                }
                opp=0;
            }
        }
        ptr--;
        target=ptr;
        
        for(int i=0;i<=target;i++){
            check[i]=false;
        }
        
        
        bfs(0);
         
        if(reach==0)return -1;
        else return answer;
    }
};
