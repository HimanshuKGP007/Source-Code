class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int prefix[n][m];
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]==1)count++;
                else count=0;
                
                prefix[i][j]=count;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //i,j is my top left coordinate for the rectangle
                int minPossibleLength=INT_MAX;
                for(int k=i;k<n;k++)
                {
                    if(prefix[k][j]<minPossibleLength)minPossibleLength=prefix[k][j];
                    ans+=minPossibleLength;
                }
            }
        }
        return ans;
    }
};
