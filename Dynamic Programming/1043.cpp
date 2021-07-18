#define pb push_back
#define vii vector<int>
const int N=501;
int dp[N];
bool check[N];
int n;
vii a;
int kSize;
int calc(int index)
{
    //cout<<"THE INDEX IS "<<index<<endl;
    int maxVal=0;
    for(int j=index;j<index+kSize && j<n;j++)
    {
        maxVal=max(maxVal,a[j]);
        if(j+1<n && check[j+1]==false)
            dp[j+1]=calc(j+1);
        

        dp[index]=max(dp[index],maxVal*(j-index+1)+dp[j+1]);
        
    }
    
    check[index]=true;
    return dp[index];
}

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        a.clear();
        kSize=k;
        for(int i=0;i<N;i++)
        {
            dp[i]=0;
            check[i]=false;
        }
        for(int i=0;i<n;i++){
            a.pb(arr[i]);
        }
        dp[n-1]=a[n-1];
        check[n-1]=true;
        
        dp[0]=calc(0);
        
      
        return dp[0];
    }
};
