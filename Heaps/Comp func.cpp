#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
using namespace std;

bool comp(pii &a,pii &b)
{
    if(a.se > b.se) return true;
    else if(a.se < b.se) return false;
    else
    {
       if(a.fi > b.fi)return true;
       else return false;
    }
}

int main() {
	// your code goes here
	
	vector<pii>a; //Pair<int,int>
	//(3,0) (100,100) (0,20) (1,200) (50,200)
	a.pb(mp(3,0));
	a.pb(mp(100,100));
	a.pb(mp(0,20));
	a.pb(mp(1,200));
	a.pb(mp(50,200));
	sort(a.begin(),a.end(),comp);
	for(int i=0;i<a.size();i++)
	{
	    cout<<a[i].fi<<";;;"<<a[i].se<<endl;
	}
	return 0;
}
