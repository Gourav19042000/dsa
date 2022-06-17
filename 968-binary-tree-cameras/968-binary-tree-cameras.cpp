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


//way to solve the question!
// Apply a recusion function dfs.
// Return 0 if it's a leaf.
// Return 1 if it's a parent of a leaf, with a camera on this node.
// Return 2 if it's coverd, without a camera on this node.
class Solution {
public:
    int ans=0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + ans; 
        
    }
    
    int dfs(TreeNode *root){
        if(!root)return 2;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==0 || right==0){
            ans++;
            return 1;
        }
        else if(left==1 || right==1)return 2;
        else return 0;
    }
};