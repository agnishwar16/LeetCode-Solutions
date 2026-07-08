class Solution:
    def twoSum(self, nums, target):
        # Dictionary to map number -> index
        seen = {}

        # Loop through the list
        for i, num in enumerate(nums):
            # Calculate the number we need
            needed = target - num
            
            # If the needed number was already seen, return result
            if needed in seen:
                return [seen[needed], i]
            
            # Otherwise, store current number with its index
            seen[num] = i
