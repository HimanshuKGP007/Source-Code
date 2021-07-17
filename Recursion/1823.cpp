#define pb push_back
#define vii vector<int>
vii a;

int calc(vii a,int k)
{
    int n=a.size();
    if(n==1)return a[0];
    
    int reqIndex=(k-1)%n;
    vii b;
    for(int i=reqIndex+1;i<n;i++)b.pb(a[i]);
    for(int i=0;i<reqIndex;i++)b.pb(a[i]);
    
    return calc(b,k);
}

class Solution {
public:
    int findTheWinner(int n, int k) {
        a.clear();
        for(int i=0;i<n;i++)a.pb(i+1);
        return calc(a,k);
    }
};


BETTER CODE::
class Solution {
public:
	int getWinner(int n,int k){
		if(n==1) return 0;  //zero based indexing
		return (getWinner(n-1,k)+k)%n; //Remove one player 
	}
	int findTheWinner(int n, int k) {
		return getWinner(n,k) + 1;
	}
};
