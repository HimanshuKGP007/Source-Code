class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>st;
        
        string s1="../";
        string s2="./";
        for(int i=0;i<logs.size();i++)
        {
            string s=logs[i];
            int val1=s.compare(s1);
            int val2=s.compare(s2);
            
            if(val1!=0 && val2!=0)st.push(1);
            if(val1==0)
            {
                if(st.size()>0)st.pop();
            }
        }
        int ans=st.size();
        return ans;
    }
};
