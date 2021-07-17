bool calc(int n)
{
    if(n==0)return false;
    if(n==1)return true;
    
    if(n%4==0)return calc(n/4);
    else return false;
}
class Solution {
public:
    bool isPowerOfFour(int n) {
        return calc(n);
    }
};
