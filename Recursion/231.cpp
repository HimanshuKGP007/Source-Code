class Solution {
public:
    bool isPowerOfTwo(int n) {
        int start=0;
        int end=32;
        while(start<=end)
        {
            int middle=start+(end-start)/2;
            if(pow(2,middle)==n)return true;
            else if(pow(2,middle)<n)start=middle+1;
            else if(pow(2,middle)>n)end=middle-1;
        }
        return false;
    }
};


int calc(int n)
{
    if(n==0)return false;
    if(n==1)return true;
    if(n%2==0)return calc(n/2);
    else return false;
}
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans=calc(n);
        return ans;
    }
};
