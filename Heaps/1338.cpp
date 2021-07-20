#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

bool comp(pii &a,pii &b)
{
    if(a.fi>b.fi)return true;
    else return false;
}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int totalSize=arr.size();
        map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            auto itr=m.find(arr[i]);
            if(itr==m.end())m.ins(mp(arr[i],1));
            else itr->se++;
        }
        vector<pii>a;
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            a.pb(mp(itr->se,itr->fi));
        }
        sort(a.begin(),a.end(),comp);
        
        /*for(int i=0;i<a.size();i++)
        {
            cout<<a[i].fi<<"-->"<<a[i].se<<endl;
        }*/
        int ans=0;
        int added=0;
        for(int i=0;i<a.size();i++)
        {
            
            if(added>=(totalSize+1)/2)break;
            else{
                added+=a[i].fi;
                ans++;
            }
        }
        return ans;
    }
};
