class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')st.push(s[i]);
            if(s[i]=='b')st.push(s[i]);
            if(s[i]=='c')
            {
                if(st.size()<2)st.push(s[i]);
                else
                {
                    char topElem=st.top();
                    st.pop();
                    char secondTopElem=st.top();
                    st.pop();
                    if(topElem=='b' && secondTopElem=='a')continue;
                    else
                    {
                        st.push(secondTopElem);
                        st.push(topElem);
                        st.push(s[i]);
                    }
                }
            }
        }
        if(st.size()==0)return true;
        else return false;
    }
};
