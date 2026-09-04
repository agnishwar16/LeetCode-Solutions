class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> leftMultiply(n);
        vector<int> rightMultiply(n);
        vector<int> answer(n);

        // Prefix product
        leftMultiply[0] = 1;

        for (int i = 1; i < n; i++) {
            leftMultiply[i] =
                leftMultiply[i - 1] * nums[i - 1];
        }

        // Suffix product
        rightMultiply[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            rightMultiply[i] =
                rightMultiply[i + 1] * nums[i + 1];
        }

        // Combine prefix and suffix
        for (int i = 0; i < n; i++) {
            answer[i] = leftMultiply[i] * rightMultiply[i];
        }

        return answer;
    }
};