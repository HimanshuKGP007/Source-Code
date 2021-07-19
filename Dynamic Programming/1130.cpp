#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>
const int N=41;
int dp[N][N];
//bool check[N][N];

int calc(int start,int end,vii &a)
{
    for(int i=start;i<=end;i++)
    {
        for(int j=i;j<end;j++)
        {
            int a1=start;int a2=j;
            int b1=j+1;int b2=end;
            
            
            if(dp[a1][a2]==INT_MAX)dp[a1][a2]=calc(a1,a2,a);
            if(dp[b1][b2]==INT_MAX)dp[b1][b2]=calc(b1,b2,a);
            int val1=dp[a1][a2];
            int val2=dp[b1][b2];
            
            int max1=INT_MIN;
            int max2=INT_MIN;
            for(int k=a1;k<=a2;k++)max1=max(max1,a[k]);
            for(int k=b1;k<=b2;k++)max2=max(max2,a[k]);
            //cout<<"THE INDEX ARE "<<a1<<" "<<a2<<"--------"<<b1<<" "<<b2<<endl;
            //cout<<"THE VALUES ARE "<<val1<<" "<<val2<<"--------"<<max1<<" "<<max2<<endl;
            //cout<<"THE START END AND ANS ARE "<<start<<" "<<end<<"------->"<<max1*max2+val1+val2<<endl;
            dp[start][end]=min(dp[start][end],max1*max2+val1+val2);
        }
    }
    return dp[start][end];
}

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=INT_MAX;
                if(i==j)dp[i][j]=0;
            }
        }
        dp[0][n-1]=calc(0,n-1,arr);
       
        return dp[0][n-1];
    }
};
