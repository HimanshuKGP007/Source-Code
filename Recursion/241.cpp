#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define pii pair<int,int>
#define vii vector<int>

multiset<int> calc(string exp)
{
    int count=0;
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]>='0' && exp[i]<='9')count++;
    }
    if(count==exp.size())
    {
        int ans=0;
        for(int i=0;i<exp.size();i++)ans=ans*10+(exp[i]-'0');
        
        multiset<int>s;
        s.ins(ans);
        return s;
    }
    
    else
    {
        int num=0;
        multiset<int>finalAns;
        
        for(int i=0;i<exp.size();i++)
        {
            if(exp[i]=='+' || exp[i]=='*' || exp[i]=='-')
            {
                string s1;
                for(int j=0;j<i;j++)s1+=exp[j];
                
                string s2;
                for(int j=i+1;j<exp.size();j++)s2+=exp[j];
                
                multiset<int>a1=calc(s1);
                multiset<int>a2=calc(s2);
                
                
                
                for(auto itr1=a1.begin();itr1!=a1.end();itr1++)
                {
                    for(auto itr2=a2.begin();itr2!=a2.end();itr2++)
                    {
                        
                        if(exp[i]=='+')finalAns.ins((*itr1)+(*itr2));
                        if(exp[i]=='-')finalAns.ins((*itr1)-(*itr2));
                        if(exp[i]=='*')finalAns.ins((*itr1)*(*itr2));
                    }
                }
            }
        }
        return finalAns;
    }
    
    
    
}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        multiset<int>a=calc(expression);   
        vii ans;
        for(auto itr=a.begin();itr!=a.end();itr++){
            ans.pb(*itr);
        }
        return ans;
    }
};
