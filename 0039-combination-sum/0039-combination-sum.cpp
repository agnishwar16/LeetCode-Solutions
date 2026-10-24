class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());

        fun(candidates,0,target,ans,temp);
        return ans;
    }
    void fun( vector<int>&candidates,int idx,int target,vector<vector<int>>&ans,vector<int>temp){

        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(idx==candidates.size()|| target<0) return;

        temp.push_back(candidates[idx]);
        fun(candidates,idx,target-candidates[idx],ans,temp);
        temp.pop_back();

        fun(candidates,idx+1,target,ans,temp);

    }
};