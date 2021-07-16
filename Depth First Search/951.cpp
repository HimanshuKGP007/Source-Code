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
int valid=1;
void check(TreeNode *x,TreeNode *y)
{
   
        if(x->val==y->val)
        {
            if(x->left!=NULL && y->left!=NULL && x->right!=NULL && y->right!=NULL)
            {
                if(x->left->val==y->left->val && x->right->val==y->right->val)
                {
                    check(x->left,y->left);
                    check(x->right,y->right);
                }
                else if(x->left->val==y->right->val && x->right->val==y->left->val)
                {
                    check(x->left,y->right);
                    check(x->right,y->left);
                }
                else valid=0;
            }
            else if(x->left==NULL && y->left!=NULL && x->right!=NULL && y->right==NULL)
            {
                if(y->left->val==x->right->val)
                {
                    check(x->right,y->left);
                }else valid=0;
            }
            else if(x->left!=NULL && y->left==NULL && x->right==NULL && y->right!=NULL)
            {
                if(y->right->val==x->left->val)
                {
                    check(x->left,y->right);
                }else valid=0;
            }
            else if(x->left==NULL && y->left==NULL && x->right==NULL && y->right==NULL)
            {
                int hello=1;
            }
            else if(x->left!=NULL && y->left!=NULL && x->right==NULL && y->right==NULL)
            {
                if(y->left->val==x->left->val)
                {
                    check(x->left,y->left);
                }else valid=0;
            }
            else if(x->left==NULL && y->left==NULL && x->right!=NULL && y->right!=NULL)
            {
                if(y->right->val==x->right->val)
                {
                    check(x->right,y->right);
                }else valid=0;
            }
            else valid=0;
        }
        else valid=0;
}
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        valid=1;
        if(root1==NULL && root2==NULL)return true;
        if(root1!=NULL && root2!=NULL)check(root1,root2);
        else return false;
        return valid;
    }
};







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
class Solution {
public:
    bool check(TreeNode* T1,TreeNode* T2){
        if(T1!=NULL && T2!=NULL){
            if(T1->val!=T2->val){
                return false;
            }
            return (check(T1->left,T2->left)&check(T1->right,T2->right))|(check(T1->left,T2->right)&check(T1->right,T2->left));
        }
        else if(T1==NULL && T2==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1,root2);
    }
};
