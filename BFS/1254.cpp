const int N=101;
int dp[N][N];
bool check[N][N];
int n,m;
int valid=1;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
bool isValid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}

void dfs(int x,int y)
{
    check[x][y]=true;
    if(x==0 || y==0 || x==n-1 || y==m-1)valid=0;
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(isValid(newX,newY) && dp[newX][newY]==0 && check[newX][newY]==false)
        {
            dfs(newX,newY);
        }
    }
}

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=grid[i][j];
                check[i][j]=false;
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(check[i][j]==false && dp[i][j]==0)
                {
                    valid=1;
                    dfs(i,j);
                    if(valid==1)ans++;
                }
            }
        }
        return ans;
    }
};
