#define pb push_back
#define vii vector<int>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
vector<vii>dp;
vector<vector<bool>>check;
vector<vii>answer;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int n,m;
vector<pii>start;

bool valid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}
void bfs(vector<pii>&a)
{
    deque<pair<pii,int>>dq;
    for(int i=0;i<a.size();i++)
    {
        dq.pb(mp(a[i],0));
        answer[a[i].fi][a[i].se]=0;
        check[a[i].fi][a[i].se]=true;
    }
    while(dq.size()>0)
    {
        pair<pii,int>top=dq.front();
        dq.pop_front();
        int x=top.fi.fi;
        int y=top.fi.se;
        int dist=top.se;
        for(int i=0;i<4;i++)
        {
            int newX=x+X[i];
            int newY=y+Y[i];
            if(valid(newX,newY) && check[newX][newY]==false)
            {
                answer[newX][newY]=dist+1;
                check[newX][newY]=true;
                dq.pb(mp(mp(newX,newY),dist+1));
            }
        }
    }
}
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        dp.clear();answer.clear();check.clear();
        start.clear();
        
        vii hello(m,INT_MAX);
        vector<bool>hello2(m,false);
        
        
        for(int i=0;i<n;i++)
        {
            vii temp;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)start.pb(mp(i,j));
                temp.pb(mat[i][j]);
            }
            dp.pb(temp);
            answer.pb(hello);
            check.pb(hello2);
        }
       
        bfs(start);
        return answer;
    }
};
