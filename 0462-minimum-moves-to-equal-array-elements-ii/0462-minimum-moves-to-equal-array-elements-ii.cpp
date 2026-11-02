class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        long long n=nums.size();
        long long target_index=n/2;

        long long total_moves=0;

        for(long long i=0;i<n;i++){

            long long curr=nums[i];

            if(nums[target_index]>curr){
                long long moves=nums[target_index]-curr;
                total_moves+=moves;
                
            }
            else if(nums[target_index]<curr){
                long long moves = curr-nums[target_index];
                total_moves+=moves;
                
            }
                
            if(nums[target_index]==curr){
                continue;
            }
        }
        return total_moves;
    }
};