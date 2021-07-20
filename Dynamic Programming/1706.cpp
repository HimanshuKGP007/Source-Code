class Solution {
public:
    

    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -2));
        
        if(n==1){
            vector<int> res={-1};
            return res;
        }
        
        for(int j=0; j<n; j++){
            if(dp[m-1][j]!=-2)continue;
            if(j==0&&grid[m-1][j]==-1){dp[m-1][j]=-1;continue;}
            else if(j==0&&grid[m-1][j]==1&&grid[m-1][j+1]==-1){dp[m-1][j]=-1;continue;}
            else if(j==0){dp[m-1][j]=1;continue;}
            
            if(j==n-1&&(grid[m-1][j]==1||grid[m-1][j-1]==1)){dp[m-1][j]=-1;continue;}
            else if(j==n-1){dp[m-1][j]==j-1; continue;}
            
            if(grid[m-1][j]==1&&grid[m-1][j+1]==-1){
                dp[m-1][j]=-1;dp[m-1][j+1]=-1;
                continue;
            }
            else if(grid[m-1][j]==1){dp[m-1][j]=j+1;continue;}
            else if(grid[m-1][j]==-1&&grid[m-1][j-1]==1){
                dp[m-1][j]=-1;dp[m-1][j-1]=-1;
                continue;
            }
            else{
                dp[m-1][j]=j-1;
                continue;
            }
            
        }
        if(grid[m-1][n-1]==-1&&grid[m-1][n-2]==-1)dp[m-1][n-1]=n-2;
        if(m==1)return dp[0];
        cout<<n;
        for(int i=m-2; i>=0; i--){
            for(int j = 0; j<n;j++){
                if(j==0&&(grid[i][j]==-1||grid[i][j+1]==-1)){
                    dp[i][j]=-1;
                    continue;
                }
                else if(j==0){
                    dp[i][j]=dp[i+1][j+1];
                    continue;
                }
                if(j==n-1&&(grid[i][j]==1||grid[i][j-1]==1)){
                    dp[i][j]=-1;continue;
                }
                else if(j==n-1){
                    dp[i][j]=dp[i+1][j-1];continue;
                }
                if(grid[i][j]==1&&grid[i][j+1]==-1){
                    dp[i][j]=-1;dp[i][j+1]=-1;
                    continue;
                }
                else if(grid[i][j]==1){dp[i][j]=dp[i+1][j+1];continue;}
                else if(grid[i][j]==-1&&grid[i][j-1]==1){
                    dp[i][j]=-1;dp[i][j-1]=-1;
                }
                else{
                    dp[i][j]=dp[i+1][j-1];
                    continue;
                }
            }
        }
        return dp[0];
        
    }
};
