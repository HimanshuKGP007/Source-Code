#define vii vector<int>
#define pb push_back
const int N=51;
int dp[N][N];
bool check[N][N];
int n,m;

int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};
int target=0;
int col=0;

void dfs(int x,int y)
{
    check[x][y]=true;
    dp[x][y]=col;
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(newX>=0 && newY>=0 && newX<n && newY<m && !check[newX][newY] && dp[newX][newY]==target)
            dfs(newX,newY);
    }
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size();
        m=image[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                dp[i][j]=image[i][j];
                check[i][j]=false;
            }
        }
        target=image[sr][sc];
        col=newColor;
        dfs(sr,sc);
        vector<vii>ans;
        for(int i=0;i<n;i++){
            vii temp;
            for(int j=0;j<m;j++)temp.pb(dp[i][j]);
            ans.pb(temp);
        }
        return ans;
    }
};
