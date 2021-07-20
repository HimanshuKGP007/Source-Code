const int N=101;
int dp[N][N];
bool check[N][N];
int n;

int calc(int x,int y,vector<vector<int>>& matrix)
{
    check[x][y]=true;
    int val1=INT_MAX;int val2=INT_MAX;int val3=INT_MAX;
    if(x+1<n && y-1>=0)
    {
        if(check[x+1][y-1]==false)dp[x+1][y-1]=calc(x+1,y-1,matrix);
        val1=dp[x+1][y-1];
    }
    if(x+1<n && y>=0 && y<n)
    {
        if(check[x+1][y]==false)dp[x+1][y]=calc(x+1,y,matrix);
        val2=dp[x+1][y];
    }
    if(x+1<n && y+1<n)
    {
        if(check[x+1][y+1]==false)dp[x+1][y+1]=calc(x+1,y+1,matrix);
        val3=dp[x+1][y+1];
    }
    dp[x][y]=matrix[x][y]+min(val1,min(val2,val3));
    return dp[x][y];
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                check[i][j]=false;
            }
        }
        
        for(int i=0;i<n;i++){
            check[n-1][i]=true;
            dp[n-1][i]=matrix[n-1][i];
        }
        
        
        int answer=INT_MAX;
        for(int i=0;i<n;i++){
            if(check[0][i]==false)
                dp[0][i]=calc(0,i,matrix);
            
            if(dp[0][i]<answer)answer=dp[0][i];
        }
        return answer;
    }
};
