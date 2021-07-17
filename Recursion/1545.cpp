int calc(int n,int k)
{
    if(n==0)return 0;
  
    else
    {
        int middleIndex=pow(2,n)-1;
        if(k==middleIndex)return 1;
        else if(k<middleIndex)
        {
            return calc(n-1,k);
        }
        else
        {
            int totSize=2*middleIndex;
            return calc(n-1,totSize-k)==0 ? 1: 0 ;
        }
        
    }
    return 0;
}
class Solution {
public:
    char findKthBit(int n, int k) {
        k--;
        n--;
        int ans=calc(n,k);
        return (ans+'0');
    }
};
