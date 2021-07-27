#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

vector<vii>answer;
int target;
int totalNums;

void calc(vii &a,vii &marked,int size,int currSum)
{
    if(size==totalNums)
    {
        if(currSum==target)
        {
            answer.pb(a);
        }
        return;
    }
    else if(size>totalNums || currSum>target)return;
    else
    {
        vii newMark(10,0);
        for(int i=1;i<=9;i++){
            newMark[i]=marked[i];
        }
        
        for(int i=1;i<=9;i++)
        {
            if(newMark[i]==0)
            {
                newMark[i]=1;
                vii newA;
                for(int j=0;j<a.size();j++)newA.pb(a[j]);
                newA.pb(i);
                
                calc(newA,newMark,size+1,currSum+i);
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        answer.clear();
        totalNums=k;
        target=n;
        
        vii a;
        vector<int>marked(10,0);
        calc(a,marked,0,0);
        
        return answer;
    }
};
