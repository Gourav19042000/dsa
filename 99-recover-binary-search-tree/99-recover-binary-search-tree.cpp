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
    
    //brute force solution!!!sort and match!o(2n+nlogn)!
   vector<int> v;int i=0;
    void inorder(TreeNode *root){
        if(root==NULL)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void maketree(TreeNode *root){
        if(!root)return ;
        maketree(root->left);
        if(root->val!=v[i])swap(root->val,v[i]);
        i++;
        maketree(root->right);
        
    }
    void recoverTree(TreeNode* root) {
      inorder(root);
        sort(v.begin(),v.end()); 
        maketree(root);
    }
};