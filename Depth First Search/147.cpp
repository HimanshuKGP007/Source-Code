#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>


const int N=201;
int graph[N][N];
bool check[N][N];
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int atlantic[N][N];
int pacific[N][N];

int n,m;


void dfs(int x,int y)
{
   
    check[x][y]=true;
    
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(newX>=0 && newY>=0 && newX<n && newY<m && check[newX][newY]==false && graph[x][y]<=graph[newX][newY])
        {
            if(atlantic[x][y]==1)atlantic[newX][newY]=1;
            if(pacific[x][y]==1)pacific[newX][newY]=1;
            dfs(newX,newY);
        }
    }
  
}
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        n=heights.size();
        m=heights[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                graph[i][j]=heights[i][j];
                check[i][j]=false;
                atlantic[i][j]=0;
                pacific[i][j]=0;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            pacific[i][0]=1;
            atlantic[i][m-1]=1;
        }
        for(int j=0;j<m;j++)
        {
            pacific[0][j]=1;
            atlantic[n-1][j]=1;
        }
        
        
        for(int i=0;i<n;i++)
        {
            dfs(i,0);
        }
        for(int j=0;j<m;j++)
        {
            dfs(0,j);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)check[i][j]=false;
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            dfs(n-1,j);
        }
        
        
        
        vector<vii>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)ans.pb({i,j});
            }
        }
        return ans;
    }
};
