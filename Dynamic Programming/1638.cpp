class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<t.size();j++)
            {
                if(s[i]!=t[j])
                {
                    int l=1;int r=1;
                    while(i-l>=0 && j-l>=0 && s[i-l]==t[j-l])l++;
                    while(i+r<s.size() && j+r<t.size() && s[i+r]==t[j+r])r++;
                    ans=ans+l*r;
                }
            }
        }
        return ans;
    }
};
