class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int counting[n];
        for(int i=0;i<n;i++)counting[i]=0;
        int start=0;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            counting[arr[i]]=1;
            int valid=1;
            for(int j=start;j<=i;j++)
            {
                if(counting[j]==0)valid=0;
            }
            if(valid==1)
            {
                ans++;
                start=i+1;
            }
        }
        return ans;
    }
};
