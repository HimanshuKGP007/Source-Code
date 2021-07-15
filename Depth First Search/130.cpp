#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
int valid=1;
const int N=201;
char dp[N][N];
bool check[N][N];
int n,m;
vector<pii>coords;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
void dfs(int x,int y)
{
    coords.pb(mp(x,y));
    check[x][y]=true;
    if(x==0 || y==0 || x==n-1 || y==m-1)valid=0;
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(newX>=0 && newY>=0 && newX<n && newY<m && check[newX][newY]==false && dp[newX][newY]=='O')dfs(newX,newY);
    }
}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                check[i][j]=false;
                dp[i][j]=board[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(check[i][j]==false && dp[i][j]=='O')
                {
                    valid=1;
                    coords.clear();
                    dfs(i,j);
                    if(valid==1)
                    {
                        for(int k=0;k<coords.size();k++)
                        {
                            int x=coords[k].fi;int y=coords[k].se;
                            board[x][y]='X';
                        }
                    }
                }
            }
        }
        
    }
};
