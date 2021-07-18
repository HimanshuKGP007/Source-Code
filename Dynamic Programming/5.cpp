const int N=1001;
int dp[N][N];
int n;
class Solution {
public:
    string longestPalindrome(string s) {
        n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(i!=j)dp[i][j]=0;
                else dp[i][j]=1;
            }
        }
        int pos=0;
        while(pos<n)
        {
            pos++;
            for(int i=0;i<n && i+pos<n;i++)
            {
                if(s[i]==s[i+pos])
                {
                    if(i+1<=i+pos-1 && dp[i+1][i+pos-1]==1)dp[i][i+pos]=1;
                    if(i+1==i+pos)dp[i][i+pos]=1;
                }
            }
        }
        int length=0;
        int start=-1;int end=-1;
        string finalAns;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1)
                {
                    int temp=j-i+1;
                    if(temp>length)
                    {
                        length=temp;start=i;end=j;
                    }
                }
            }
        }
        for(int i=start;i<=end;i++)finalAns+=s[i];
        return finalAns;
    }
};
