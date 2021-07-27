#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

int n;
int finalAns=INT_MAX;
vector<int>price;
vector<vii>special;
vector<int>needs;

void calc(vii &weHave,int cost)
{
    int greater=0;
    for(int i=0;i<n;i++)
    {
        if(weHave[i]>needs[i])greater=1;
    }
    if(greater==1)return;
    else if(greater==0)
    {
        int tempCost=0;
        for(int i=0;i<n;i++)
        {
            int val=(needs[i]-weHave[i])*price[i];
            tempCost+=val;
        }
        finalAns=min(finalAns,cost+tempCost);
   
        
        for(int i=0;i<special.size();i++)
        {
            vii newWeHave;
            for(int j=0;j<weHave.size();j++){
                newWeHave.pb(weHave[j]);
            }
            for(int j=0;j<n;j++){
                newWeHave[j]+=special[i][j];
            }
            
            calc(newWeHave,cost+special[i][n]);
        }
    }
}

class Solution 
{
public:
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& need) 
    {
        price.clear();
        special.clear();
        needs.clear();
        
        for(int i=0;i<p.size();i++)price.pb(p[i]);
        for(int i=0;i<s.size();i++)special.pb(s[i]);
        for(int i=0;i<need.size();i++)needs.pb(need[i]);
        
        n=needs.size();
        finalAns=INT_MAX;
        
        vii req(n,0);
        calc(req,0);
        return finalAns;
    }
};
