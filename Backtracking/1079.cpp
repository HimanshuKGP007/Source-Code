#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
int ans=0;
int n;
set<string>s;
string mainStr;

void calc(string &newStr,vector<int>&validity,int len)
{
    if(len==0)
    {
        auto itr=s.find(newStr);
        if(itr==s.end())
        {
            ans++;
            s.ins(newStr);
        }
    }
    else
    {
        for(int i=0;i<validity.size();i++)
        {
            if(validity[i]==1) // We can use that char
            {
                vector<int>newValid;
                for(int j=0;j<validity.size();j++)
                {
                    newValid.pb(validity[j]);
                }
            
                string copy=newStr;
                copy+=mainStr[i];
                newValid[i]=0;
                calc(copy,newValid,len-1);
            }
         }
     }
}
class Solution {
public:
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        ans=0;
        vii valid(n,1);
        s.clear();
        mainStr=tiles;
        for(int i=1;i<=n;i++)
        {
            string temp="";
            calc(temp,valid,i);
        }
        return ans;
    }
};
