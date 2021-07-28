/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

map<int,int>m;
vector<pii>a;  //NUM, HEIGHT
int ptr=0;
TreeNode *calc(int presentIndex)
{
    TreeNode *node=new TreeNode();
    node->val=a[ptr].fi;
    ptr++;
    
    if(ptr<a.size() && a[ptr].se==a[presentIndex].se+1) //Make Left child
    {
        node->left=calc(ptr);
    }
    if(ptr<a.size() && a[ptr].se==a[presentIndex].se+1) //Make Right child
    {
        node->right=calc(ptr);
    }
    return node;
}
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        ptr=0;
        a.clear();
        m.clear();
        int dashes=0;
        int num=0;
        for(int i=0;i<traversal.size();i++)
        {
            if(traversal[i]>='0' && traversal[i]<='9')
            {
                num=num*10+(traversal[i]-'0');
            }
            else
            {
                if(num!=0)
                {
                    a.pb(mp(num,dashes));
                    num=0;
                    dashes=0;
                }
                if(num==0)
                {
                    dashes++;
                }
            }
        }
        a.pb(mp(num,dashes));
       
      
        TreeNode *root=calc(0);
        return root;
    }
};
