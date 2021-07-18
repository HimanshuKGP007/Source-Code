
vector<int> dp(1e7+1, -1);

class Solution {
public:
    
    int dpdp(int x, vector<int> &dp){
        if(x==1)return 0;
        if(dp[x]!=-1)return dp[x];
        else{
            int find;
            if(x%2==0)find = dpdp(x/2, dp);
            else find = dpdp(3*x+1, dp);
            dp[x]=find+1;
            return dp[x];
        }
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> res;
        for(int i = lo; i<=hi; i++){
            res.push_back(make_pair(dpdp(i,dp),i));
        }
        sort(res.begin(), res.end());
        
        return res[k-1].second;
        
    }
};
