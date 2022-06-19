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

//umderstood striver concept but code here is better!
class Solution {
public:
    TreeNode *nextgrater(TreeNode *curr){
        curr=curr->right;
        while(curr!=NULL && curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    //THE CODE IS REALLY HARD FOR BEGINNERS
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root==NULL)return root;
        if(root->val>val){
            root->left=deleteNode(root->left,val);
        }
        else if(root->val<val){
            root->right=deleteNode(root->right,val);
        }
        else{
             if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
           else if(root->left==NULL){
              TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
             else{
             TreeNode *temp=root->left;
             while(temp->right)temp=temp->right;
            temp->right=root->right;
            return root->left;
             }
            // else{
            //     TreeNode *l=nextgrater(root);
            //     root->val=l->val;
            //     root->right=deleteNode(root->right,l->val);
            // }
           
            
        }
        return root;
    }
};