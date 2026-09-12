#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize) {

    int left = 0;
    int sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < numsSize; right++) {

    
        sum += nums[right];

        
        while (sum >= target) {

            int length = right - left + 1;

            if (length < ans) {
                ans = length;
            }

        
            sum -= nums[left];
            left++;
        }
    }

    // No valid subarray found
    if (ans == INT_MAX) {
        return 0;
    }

    return ans;
}

