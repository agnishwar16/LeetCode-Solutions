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
    void helper(TreeNode* root,int currentSum,int targetSum,vector<int>& path,vector<vector<int>>&ans){
        if (root==NULL) return ;
        path.push_back(root->val);
        currentSum+=root->val;
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==currentSum){
                ans.push_back(path);
            }
        }
        helper(root->left,currentSum,targetSum,path,ans);
        helper(root->right,currentSum,targetSum,path,ans);
        path.pop_back();

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>path;
        helper (root,0,targetSum,path,ans);
        return ans;
    }
};