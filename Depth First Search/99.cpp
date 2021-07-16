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
vii a;
int ptr=0;
void inorder1(TreeNode *root)
{
    if(root->left!=NULL)inorder1(root->left);
    a.pb(root->val);
    if(root->right!=NULL)inorder1(root->right);
}
void inorder2(TreeNode *root)
{
    if(root->left!=NULL)inorder2(root->left);
    root->val=a[ptr];
    ptr++;
    if(root->right!=NULL)inorder2(root->right);
}
void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        a.clear();
        ptr=0;
        inorder1(root);
        sort(a.begin(),a.end());
        inorder2(root);
    }
};
