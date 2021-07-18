const int N=1001;
int dp[3][N];

class Solution {
public:
    int twoEggDrop(int n) {
        
        for(int i=0;i<3;i++){
            for(int j=0;j<=n;j++)dp[i][j]=0;
        }
        
        for(int i=0;i<=n;i++)dp[1][i]=i;
        dp[2][1]=1;
        
        for(int i=2;i<=n;i++)
        {
            int start=1;int end=i-1;
            int actualAns=INT_MAX;
            for(int j=start;j<=end;j++)
            {
                //BREAK,NO BREAK
                int ans1=1+dp[1][j-1]; //BREAK
                int ans2=1+dp[2][i-j]; //NO BREAK
                actualAns=min(actualAns,max(ans1,ans2));
            }
            dp[2][i]=actualAns;
        }
        return dp[2][n];
    }
};
