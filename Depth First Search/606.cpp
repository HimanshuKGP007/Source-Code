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
string finalAns;
void traverse(TreeNode *root)
{
    finalAns+='(';
    
    if(root->val>0)
    {
        string temp;
        int num=root->val;
        while(num>0){
            temp+=(num%10+'0');
            num/=10;
        }
        reverse(temp.begin(),temp.end());
        finalAns+=temp;
        
    }
    else if(root->val==0)finalAns+='0';
    else 
    {
        finalAns+='-';
        string temp;
        int num=abs(root->val);
        while(num>0){
            temp+=(num%10+'0');
            num/=10;
        }
        reverse(temp.begin(),temp.end());
        finalAns+=temp;
    }
    
    if(root->left==NULL && root->right==NULL){
        finalAns+=')';
        return;
    }
    
    if(root->left!=NULL)traverse(root->left);
    else finalAns+="()";
    if(root->right!=NULL)traverse(root->right);
    finalAns+=')';
    
}

class Solution {
public:
    string tree2str(TreeNode* root) {
        finalAns="";
        traverse(root);
        string ans="";
        for(int i=1;i<finalAns.size()-1;i++)ans+=finalAns[i];
        return ans;
    }
};
