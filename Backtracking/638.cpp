\\\\\\\\\\\12ms\\\\\\\\\\\88%fatser\\\\\\\\\\\\\\\

class Solution {
public:
    
    map<vector<int>, int> m;                                // map to store vector of needs and it scorresponding minimum cost
    
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int> &m){
        if(m.find(needs)!=m.end())return m[needs];
        int minimum = INT_MAX/2;                            //putting INT_MAX may make it ot of bounds
        int n = needs.size();
        
        int maxi = *max_element(needs.begin(), needs.end());
        if(maxi==0)return 0;                                // checking if all zero;
        
        for(int i=0; i<special.size(); i++){
            int minim=INT_MAX;
            for(int j=0; j<n; j++){                         // checking if minimum value in needs is less than 0, then we won't consider the case
                needs[j] = needs[j]-special[i][j];
                minim = min(minim, needs[j]);
            }
            
            if(minim>=0)minimum = min(minimum, special[i][n]+helper(price, special, needs,m));
            for(int j=0; j<n; j++){
                needs[j] = needs[j]+special[i][j];
            }
        }
        int price_no_offer = 0;                             //price if no offer was used
        for( int i=0; i<n; i++){
            if(needs[i]!=0)price_no_offer+=needs[i]*price[i];
        }
        minimum = min(minimum, price_no_offer);
        m[needs]=minimum;                                   // update in map
        return minimum;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        m.clear();
        return helper(price,special, needs,m);
    }
};

\\\\\\\\\\\\\\\\\\\\\\\\\\\

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
