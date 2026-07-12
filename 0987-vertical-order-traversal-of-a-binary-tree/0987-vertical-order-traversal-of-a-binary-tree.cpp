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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        map<int,map<int,multiset<int>>>mp;

        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp= q.front();
            q.pop();

            TreeNode *node=temp.first;
            int x=temp.second.first;
            int y= temp.second.second;

            mp[x][y].insert(node->val);

            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }if(node->right){
                q.push({node->right,{x+1,y+1}});
            }

        }

        for (auto x:mp){
            vector<int> column;

            for (auto y:x.second){
                
                for (auto node:y.second){
                    column.push_back(node);
                }
            }
            ans.push_back(column);
        }
        
        return ans;
    }

};