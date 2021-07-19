#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N=1e4+1;
vector<int>graph[N];
vector<bool>check(N,false);
vector<int>checkRoot(N,1);
int valid=1;
class Solution {
public:
    void dfs(int v)
    {
        check[v]=true;
        for(int i=0;i<graph[v].size();i++)
        {
            int u=graph[v][i];
            if(check[u]==false)
            {
                dfs(u);
            }else valid=0;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        valid=1;
        for(int i=0;i<n;i++){
            check[i]=false;
            checkRoot[i]=1;
            graph[i].clear();
        }
        
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                graph[i].pb(leftChild[i]);
                checkRoot[leftChild[i]]=0;
            }
            if(rightChild[i]!=-1)
            {
                graph[i].pb(rightChild[i]);
                checkRoot[rightChild[i]]=0;
            }
        }
        int root=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(checkRoot[i]==1){
                count++;
                root=i;
            }
        }
        if(count>1 || count==0)return false;
        else{
            dfs(root);
            for(int i=0;i<n;i++){
                if(check[i]==false)valid=0;
            }
            if(valid==1)return true;
            else return false;
        }
    }
};
