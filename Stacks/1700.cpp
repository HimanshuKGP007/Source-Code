class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& a) {
        int ones=0;
        int zeros=0;
        
        for(int i=0;i<students.size();i++)
        {
            if(students[i]==1)ones++;
            else zeros++;
        }
        stack<int>st;
        int n=a.size();
        for(int i=n-1;i>=0;i--)
        {
            st.push(a[i]);
        }
        while(st.size()>0)
        {
            if(st.top()==1 && ones>0)
            {
                st.pop();ones--;
            }
            else if(st.top()==0 && zeros>0)
            {
                st.pop();zeros--;
            }
            else break;
        }
        int ans=st.size();
        return ans;
    }
};
