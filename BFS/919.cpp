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
deque<TreeNode*>dq;
TreeNode *mainNode;
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        mainNode=root;
        dq.clear();
        dq.pb(root);
        while(true)
        {
            TreeNode *topNode=dq.front();
            if(topNode->left!=NULL && topNode->right!=NULL)
            {
                dq.pop_front();
                dq.pb(topNode->left);
                dq.pb(topNode->right);
            }
            if(topNode->left!=NULL && topNode->right==NULL)
            {
                dq.pb(topNode->left);
                break;
            }
            if(topNode->left==NULL && topNode->right==NULL)break;
        }
    }
    
    int insert(int v) {
        TreeNode *newNode=new TreeNode();
        newNode->val=v;
        
        
        TreeNode* topNode=dq.front();
        if(topNode->left==NULL && topNode->right==NULL)
        {
            topNode->left=newNode;
            dq.pb(newNode);
        }
        else if(topNode->left!=NULL && topNode->right==NULL)
        {
            topNode->right=newNode;
            dq.pb(newNode);
            dq.pop_front();
        }
        return topNode->val;
    }
    
    TreeNode* get_root() {
        return mainNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
