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
#define vii vector<int>
vector<vii>ans;
void dfs(TreeNode *root,vii a)
{
    a.pb(root->val);
    if(root->left==NULL && root->right==NULL)
    {
        ans.pb(a);
    }
    if(root->left!=NULL){
        vii b;
        for(int i=0;i<a.size();i++)b.pb(a[i]);
        dfs(root->left,b);
    }
    if(root->right!=NULL){
        vii c;
        for(int i=0;i<a.size();i++)c.pb(a[i]);
        dfs(root->right,c);
    }
}
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vii a;
        ans.clear();
        dfs(root,a);
        vector<string>ansFIN;
        for(int i=0;i<ans.size();i++)
        {
            string finalAns;
            finalAns+=to_string(ans[i][0]);
            int n=ans[i].size();
            for(int j=1;j<ans[i].size();j++)
            {
                finalAns+="->";finalAns+=to_string(ans[i][j]);
            }
        
            ansFIN.pb(finalAns);
        }
        return ansFIN;
    }
};
