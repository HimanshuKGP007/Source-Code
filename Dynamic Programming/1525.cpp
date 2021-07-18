const int N=1e5+1;
const int M=26;
int leftA[N][M];
int rightA[N][M];
class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++){
                leftA[i][j]=0;
                rightA[i][j]=0;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(i==0)leftA[i][s[i]-'a']=1;
            else
            {
                for(int j=0;j<26;j++)
                {
                    leftA[i][j]=leftA[i-1][j];
                }
                leftA[i][s[i]-'a']++;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)rightA[i][s[i]-'a']=1;
            else
            {
                for(int j=0;j<26;j++)
                {
                    rightA[i][j]=rightA[i+1][j];
                }
                rightA[i][s[i]-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int count1=0;int count2=0;
            for(int j=0;j<26;j++){
                if(leftA[i][j]>0)count1++;
            }
            for(int j=0;j<26;j++){
                if(rightA[i+1][j]>0)count2++;
            }
            if(count1==count2)ans++;
        }
        return ans;
    }
};
