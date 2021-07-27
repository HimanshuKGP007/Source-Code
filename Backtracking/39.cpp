#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
int n;
vii a;
int target;
set<vii>ans;

void calc(vii &temp,int t)
{
    if(t==target)
    {
        sort(temp.begin(),temp.end());
        ans.ins(temp);
        return;
    }
    else if(t>target)return ;
    else
    {
        for(int i=0;i<n;i++)
        {
            vii newTemp;
            for(int j=0;j<temp.size();j++){
                newTemp.pb(temp[j]);
            }
            newTemp.pb(a[i]);
            calc(newTemp,t+a[i]);
        }
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int t) {
        a.clear();
        ans.clear();
        n=candidates.size();
        target=t;
        for(int i=0;i<n;i++)
        {
            a.pb(candidates[i]);
        }
        vii temp;
        calc(temp,0);
        vector<vii>finalAns;
        for(auto itr=ans.begin();itr!=ans.end();itr++)finalAns.pb(*itr);
        return finalAns;
    }
};
