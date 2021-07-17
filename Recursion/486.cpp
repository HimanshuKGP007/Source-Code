#define pb push_back
#define mp make_pair
#define vii vector<int>
const int N=21;
int dp[N][N];
bool check[N][N];
int n;
vii a;



bool valid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<n)return true;
    else return false;
}
int calc(int l,int r)
{
    if(l>r)return 0;
    
    else if(l==r)
    {
        check[l][r]=true;
        dp[l][r]=a[l];
        return dp[l][r];
    }
    else
    {
        check[l][r]=true;
        
        int v1=0;int v2=0;int v3=0;int v4=0;
        
        if(valid(l+2,r))
        {
            if(check[l+2][r]==false)v1=calc(l+2,r);
            else v1=dp[l+2][r];
        }
        if(valid(l+1,r-1))
        {
            if(check[l+1][r-1]==false)v2=calc(l+1,r-1);
            else v2=dp[l+1][r-1];
        }
        if(valid(l,r-2))
        {
            if(check[l][r-2]==false)v3=calc(l,r-2);
            v3=dp[l][r-2];
        }
        if(valid(l+1,r-1))
        {
            if(check[l+1][r-1]==false)v4=calc(l+1,r-1);
            else v4=dp[l+1][r-1];
        }
        
        
        int val1=(a[l]+min(v1,v2));
        int val2=(a[r]+min(v3,v4));
        dp[l][r]=max(val1,val2);
        
        return dp[l][r];
    }
}

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        n=nums.size();
        if(n<=2)return true;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                dp[i][j]=0;
                check[i][j]=false;
            }
        }
        a.clear();
        int sum=0;
        for(int i=0;i<n;i++){
            a.pb(nums[i]);sum+=nums[i];
        }
        dp[0][n-1]=calc(0,n-1);
        if(dp[0][n-1]>=sum-dp[0][n-1])return true;
        else return false;
    }
};
