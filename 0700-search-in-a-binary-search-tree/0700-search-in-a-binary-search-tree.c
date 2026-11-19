/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return root;
    if(val<root->val)
        return searchBST(root->left,val);
    if(val>root->val)
        return searchBST(root->right,val);
    else{
        return root;
    }
}