class Solution:
    def maxProduct(self, nums):
        length = len(nums)
        max_product = float('-inf')
        x = 1

        for i in range(length):
            x = 1 if nums[i] == 0 else x * nums[i]
            nums[i] = 0 if nums[i] == 0 else x

        first_neg = -1

        for i in range(length):
            max_product = max(max_product, nums[i])
            if nums[i] < 0 and first_neg == -1:
                first_neg = i
            elif nums[i] == 0 and first_neg != -1:
                if i == 0:
                    continue
                if i - 1 == first_neg:
                    first_neg = -1
                    continue
                max_product = max(max_product, nums[i - 1] // nums[first_neg])
                first_neg = -1

        if first_neg != -1 and length - 1 != first_neg:
            max_product = max(max_product, nums[length - 1] // nums[first_neg])

        for i in range(length):
            print(nums[i], end=" ")
        print()

        return max_product
