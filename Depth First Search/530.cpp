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
vii a;
void inorder(TreeNode *root)
{
    if(root->left!=NULL)inorder(root->left);
    a.pb(root->val);
    if(root->right!=NULL)inorder(root->right);
}
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        a.clear();
        inorder(root);
        int ans=INT_MAX;
        for(int i=1;i<a.size();i++){
            ans=min(ans,a[i]-a[i-1]);
        }
        return ans;
    }
};
