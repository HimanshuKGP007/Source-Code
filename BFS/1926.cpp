#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

const int N=101;
int dp[N][N];
bool check[N][N];
int n,m;
pii start;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int ans=INT_MAX;

bool valid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}

void bfs(pii a)
{
    int x=a.fi;
    int y=a.se;
    check[x][y]=true;
    dp[x][y]=0;
    deque<pair<pii,int>>dq;
    dq.pb(mp(mp(x,y),0));
    
    while(dq.size()>0)
    {
        pair<pii,int> top=dq.front();
        dq.pop_front();
        x=top.fi.fi;
        y=top.fi.se;
        int height=top.se;
        if(x==0 || y==0 || x==n-1 || y==m-1)
        {
            if(!(x==start.fi && y==start.se))
            {
                if(height<ans)ans=height;
            }
        }
        for(int i=0;i<4;i++)
        {
            int newX=x+X[i];
            int newY=y+Y[i];
            
            if(valid(newX,newY) && check[newX][newY]==false && dp[newX][newY]==1)
            {
                check[newX][newY]=true;
                dq.pb(mp(mp(newX,newY),height+1));
            }
        }
        
    }
}

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        n=maze.size();
        m=maze[0].size();
        ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(maze[i][j]=='+')
                    dp[i][j]=0;
                else dp[i][j]=1;
                
                check[i][j]=false;
            }
        }
        start=mp(entrance[0],entrance[1]);
        bfs(start);
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
