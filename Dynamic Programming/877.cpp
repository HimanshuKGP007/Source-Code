#define pb push_back
#define vii vector<int>

const int N=501;
int dp[N][N];
bool check[N][N];
vii a;
int n;

bool valid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<n)return true;
    else return false;
}
int calc(int l,int r)
{
    int val1=0;int val2=0;int val3=0;int val4=0;
    
    if(valid(l+2,r))
    {
        if(check[l+2][r]==false)dp[l+2][r]=calc(l+2,r);
        val1=dp[l+2][r];
    }
    if(valid(l+1,r-1))
    {
        if(check[l+1][r-1]==false)dp[l+1][r-1]=calc(l+1,r-1);
        val2=dp[l+1][r-1];
    }
    if(valid(l+1,r-1))
    {
        if(check[l+1][r-1]==false)dp[l+1][r-1]=calc(l+1,r-1);
        val3=dp[l+1][r-1];
    }
    if(valid(l,r-2))
    {
        if(check[l][r-2]==false)dp[l][r-2]=calc(l,r-2);
        val4=dp[l][r-2];
    }
    check[l][r]=true;
    dp[l][r]=max(a[l]+min(val1,val2),a[r]+min(val3,val4));
    return dp[l][r];
    
}

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        a.clear();
        int sum=0;
        for(int i=0;i<n;i++){
            a.pb(piles[i]);
            sum+=piles[i];
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                check[i][j]=false;
                dp[i][j]=0;
            }
        }
        
        dp[0][n-1]=calc(0,n-1);
        int sum1=dp[0][n-1];
        int sum2=sum-dp[0][n-1];
        if(sum1>=sum2)return true;
        else return false;
    }
    
};
