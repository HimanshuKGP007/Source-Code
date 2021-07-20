/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
#define vii vector<int>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

const int N=501;
vector<int>graph[N];
vector<bool>check(N,false);
int dest;
int len;
vii ans;


void bfs(int v)
{
    check[v]=true;
    deque<pii>dq;
    dq.pb(mp(v,0));
    while(dq.size()>0)
    {
        pii top=dq.front();
        dq.pop_front();
        if(top.se==len)ans.pb(top.fi);
        int u=top.fi;
        
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[top.fi][i];
            if(check[v]==false)
            {
                check[v]=true;
                dq.pb(mp(v,top.se+1));
            }
        }
    }
}

void createGraph(TreeNode *root)
{
    deque<TreeNode*>dq;
    dq.pb(root);
    while(dq.size()>0)
    {
        TreeNode *top=dq.front();
        dq.pop_front();
        int u=top->val;
        
        if(top->left!=NULL)
        {
            int v=top->left->val;
            dq.pb(top->left);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        if(top->right!=NULL)
        {
            int v=top->right->val;
            dq.pb(top->right);
            graph[u].pb(v);
            graph[v].pb(u);
        }
    }
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        for(int i=0;i<N;i++){
            check[i]=false;
            graph[i].clear();
        }
        createGraph(root);
        dest=target->val;
        len=k;
        ans.clear();
        bfs(dest);
        return ans;
    }
};
