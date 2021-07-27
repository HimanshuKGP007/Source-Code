#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
int numbers;
int total;
vector<vii>ans;

void calc(vii &a,vii &marked,int size)
{
    if(size==numbers)
    {
        ans.pb(a);
        return ;
    }
    else if(size>numbers)return ;
    else
    {
        vii newMarked(total+1,0);
        for(int i=1;i<=total;i++){
            newMarked[i]=marked[i];
        }
        for(int i=1;i<=total;i++)
        {
            if(newMarked[i]==0)
            {
                newMarked[i]=1;
                vii newA;
                for(int j=0;j<a.size();j++)newA.pb(a[j]);
                newA.pb(i);
                calc(newA,newMarked,size+1);
            }
        }
    }
}


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        total=n;
        numbers=k;
        
        vector<int>marked(n+1,0);
        vii a;
        calc(a,marked,0);
        return ans;
    }
};
