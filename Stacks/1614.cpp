class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int answer=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                if(st.size()>answer)answer=st.size();
            }
            else if(s[i]==')')
            {
                st.pop();
            }
        }
        return answer;
    }
};
