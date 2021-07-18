#define vii vector<int>
#define pb push_back
const int N=20;
vector<int>storeDigits(N,0);

class Solution {
public:
    vector<int> countBits(int n) {
        vii ans; 
        for(int i=0;i<N;i++)storeDigits[i]=0;
        
        ans.pb(0);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(storeDigits[j]==0){
                    storeDigits[j]=1;
                    break;
                }
                else{
                    storeDigits[j]=0;
                }
            }
            int count=0;
            for(int j=0;j<N;j++){
                if(storeDigits[j]==1)count++;
            }
            ans.pb(count);
        }
        return ans;
    }
};
