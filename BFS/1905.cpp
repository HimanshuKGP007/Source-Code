const int N=501;
int dp1[N][N];
int dp2[N][N];
bool check[N][N];
int n,m;
int valid=1;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int colour=0;


bool isValid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}

void dfs(int x,int y,int value)
{
    check[x][y]=true;
    dp1[x][y]=value;
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(isValid(newX,newY) && check[newX][newY]==false && dp1[newX][newY]==1)
        {
            dfs(newX,newY,value);
        }
    }
}

void dfs2(int x,int y)
{
    check[x][y]=true;
    if(colour!=dp1[x][y])valid=0;
    
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(isValid(newX,newY) && check[newX][newY]==false && dp2[newX][newY]==1)
        {
            dfs2(newX,newY);
        }
    }
}



class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size();
        m=grid1[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                check[i][j]=false;
                dp1[i][j]=grid1[i][j];
                dp2[i][j]=grid2[i][j];
            }
        }
        
        int value=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(check[i][j]==false && dp1[i][j]==1)
                {
                    dfs(i,j,value);
                    value++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                check[i][j]=false;
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                cout<<dp1[i][j]<<" ";
            }cout<<endl;
        }*/
        
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                valid=1;
                if(check[i][j]==false && dp2[i][j]==1 && dp1[i][j]!=0)
                {
                    colour=dp1[i][j];
                    dfs2(i,j);
                    if(valid==1)ans++;
                }
                
            }
        }
        
        return ans;
    }
};
