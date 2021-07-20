#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>

bool comp(pair<char,int>&a,pair<char,int>&b)
{
    if(a.se>b.se)return true;
    else return false;
}

class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        for(int i=0;i<s.size();i++)
        {
            auto itr=freq.find(s[i]);
            if(itr==freq.end())freq.ins(mp(s[i],1));
            else itr->se++;
        }
        vector<pair<char,int>>a;
        for(auto itr=freq.begin();itr!=freq.end();itr++)
        {
            a.pb(mp(itr->fi,itr->se));
        }
        sort(a.begin(),a.end(),comp);
        string finalAns;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[i].se;j++)finalAns+=a[i].fi;
        }
        return finalAns;
    }
};





///////////////////CODE 2
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>




class Solution {
public:
    string frequencySort(string s) {
        priority_queue< pair<int,char> >pq; //,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            auto itr=m.find(s[i]);
            if(itr==m.end())m.ins(mp(s[i],1));
            else itr->se++;
        }
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            pq.push(mp(itr->se,itr->fi));
        }
        string ans;
        while(pq.size()>0)
        {
            pair<int,char>elem=pq.top();
            pq.pop();
            for(int i=0;i<elem.fi;i++)ans+=elem.se;
        }
        return ans;
    }
};










