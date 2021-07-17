void recurse(vector<char>&s,int start,int end)
{
    swap(s[start],s[end]);
    if(start+1<end-1)
    recurse(s,start+1,end-1);
}
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        if(0<n-1)
            recurse(s,0,n-1);
    }
};
