#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

int ans=0;
const int N=2*30+1;
bool check[N];
map<int,int>m1;
map<int,int>m2;
int n;

void dfs(int u)
{
    check[u]=true;
    ans++;
    if(u%2==0) //FIND u+1
    {
        auto itr1=m1.find(u);
        auto itr2=m2.find(u);
        
        if(itr1!=m1.end())
        {
            int v=itr1->se;
            if(check[v]==false)
            {
                dfs(v);
            }
            if(check[u+1]==false)
            {
                dfs(u+1);
            }
        }
        if(itr2!=m2.end())
        {
            int v=itr2->se;
            if(check[v]==false)
            {
                dfs(v);
            }
            if(check[u+1]==false)
            {
                dfs(u+1);
            }
        }
    }
    
    
    else if(u%2==1) //FIND u-1
    {
        auto itr1=m1.find(u);
        auto itr2=m2.find(u);
        
        if(itr1!=m1.end())
        {
            int v=itr1->se;
            if(check[v]==false)
            {
                dfs(v);
            }
            if(check[u-1]==false)
            {
                dfs(u-1);
            }
        }
        if(itr2!=m2.end())
        {
            int v=itr2->se;
            if(check[v]==false)
            {
                dfs(v);
            }
            if(check[u-1]==false)
            {
                dfs(u-1);
            }
        }
    }
}

class Solution {
public:
    int minSwapsCouples(vector<int>& row) 
    {
        n=row.size();
        n/=2;
        m1.clear();
        m2.clear();
        for(int i=0;i<2*n;i++)
        {
            check[i]=false;
        }
        
        for(int i=0;i<row.size();i=i+2)
        {
            int u=row[i];
            int v=row[i+1];
            m1.ins(mp(u,v));
            m2.ins(mp(v,u));
        }
        
        int finalAns=0;
        for(int i=0;i<2*n;i++)
        {
            if(check[i]==false)
            {
                ans=0;
                dfs(i);
                finalAns+=((ans/2)-1);
            }
        }
        return finalAns;
    }
};
