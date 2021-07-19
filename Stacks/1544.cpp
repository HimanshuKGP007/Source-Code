class Solution {
public:
    string makeGood(string s) {
        map<char,char>m1;
        map<char,char>m2;
        for(int i=0;i<26;i++)
        {
            m1['a'+i]='A'+i;
            m2['A'+i]='a'+i;
        }
        
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.size()==0)st.push(s[i]);
            else
            {
                char topChar=st.top();
                auto itr1=m1.find(topChar);
                auto itr2=m2.find(topChar);
                
                int val=1;
                
                if(itr1!=m1.end())
                {
                    if(itr1->second==char(s[i])){
                        st.pop();val=0;
                    }
                }
                
                if(itr2!=m2.end())
                {
                    if(itr2->second==char(s[i])){
                        st.pop();val=0;
                    }
                }
                
                if(val==1)st.push(s[i]);
            }
        }
        string finalAns;
        while(st.size()>0){
            char x=st.top();
            finalAns+=x;
            st.pop();
        }
        if(finalAns.size()>0)reverse(finalAns.begin(),finalAns.end());
        return finalAns;
    }
};
