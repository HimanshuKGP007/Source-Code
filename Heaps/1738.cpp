class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n,m;
        n=matrix.size();
        m=matrix[0].size();
        int cumRow[n][m];
        int cumMatrix[n][m];
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                cumRow[i][j]=0;
                cumMatrix[i][j]=0;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            cumRow[i][0]=matrix[i][0];
            for(int j=1;j<m;j++)
            {
                cumRow[i][j]=cumRow[i][j-1]^matrix[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)cumMatrix[0][j]=cumRow[0][j];
                else
                    cumMatrix[i][j]=cumMatrix[i-1][j]^cumRow[i][j];
            }
        }
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
              
                pq.push(cumMatrix[i][j]);
            }
        }
        int ans=0;
        while(k--)
        {
            ans=pq.top();pq.pop();
        }
        return ans;
    }
};
