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
    int maxWidth=0;
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;

        q.push({root,0});

        while(!q.empty()){

            int size=q.size();
            long long minIndex=q.front().second;

            long long firstIndex;
            long long secondIndex;

            for (int i=0;i<size;i++){

                auto temp=q.front();
                TreeNode *node=temp.first;
                long long index=temp.second;
                q.pop();
                long long currIndex=index-minIndex;

                if (i==0){
                    firstIndex=currIndex;
                }
                if(i==size-1){
                    secondIndex=currIndex;
                }

                if(node->left){
                q.push({node->left,currIndex*2+1});
                }if(node->right){
                q.push({node->right,currIndex*2+2});
                }
                

            }
            int Width=secondIndex-firstIndex+1;
            maxWidth=max(maxWidth,Width);

            
        }

        return maxWidth;
    }
};