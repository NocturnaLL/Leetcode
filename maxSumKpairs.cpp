#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



/*

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109*/

// Solution 1: Using Two Pointer Approach with a Temporary Array
class Solution1 {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int numOp = 0;
        vector<int> temp = nums;

        for (int i = 0; i < nums.size(); i++) {
            while (i < right) {
                if (nums[left] + nums[right] == k && temp[left] && temp[right]) {
                    numOp++;
                    temp[left] = 0;
                    temp[right] = 0;
                }
                right--;
            }
            right = nums.size() - 1;
            left++;
        }
        return numOp;
    }
};

// Solution 2: Using Hash Map to Track Frequencies
class Solution2 {
public:
int maxOperations(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int> umap;
        int countOp=0;

        for(int i=0;i<size;i++){
            umap[nums[i]]++;
        }

        for(int i=0;i<size;i++){
            int diff = k - nums[i];
            if(umap[diff]>0 && umap[nums[i]]>0){
                if(diff==nums[i]){
                    if(umap[nums[i]]>=2){
                        umap[nums[i]]-=2;
                        countOp++;
                    }
                }
                else{
                    umap[diff]--;
                    umap[nums[i]]--;
                    countOp++;
                }

            }
        }
        return countOp;

    }
};

// Main function to test both solutions
int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 1, 3, 4, 3};
    int k1 = 5;
    int k2 = 6;

    Solution1 sol1;
    int result1 = sol1.maxOperations(nums1, k1);
    printf



int maxOperations(int* nums, int numsSize, int k) {
    int maxValue = 100000; // A reasonable limit based on constraints
    int* count = (int*)calloc(maxValue, sizeof(int));
    int countOp = 0;

    // Count occurrences of each element using pointer arithmetic
    for (int i = 0; i < numsSize; i++) {
        *(count + *(nums + i)) += 1; // Equivalent to count[nums[i]]++
    }

    // Find pairs that sum up to k
    for (int i = 0; i < numsSize; i++) {
        int num = *(nums + i);
        int diff = k - num;

        // Check if both num and its complement are available
        if (diff >= 0 && *(count + num) > 0 && *(count + diff) > 0) {
            if (num == diff) {
                // If num and diff are the same, ensure there are at least two instances
                if (*(count + num) >= 2) {
                    *(count + num) -= 2; // Equivalent to count[num] -= 2
                    countOp++;
                }
            } else {
                // If num and diff are different
                *(count + num) -= 1;   // Equivalent to count[num]--
                *(count + diff) -= 1;  // Equivalent to count[diff]--
                countOp++;
            }
        }
    }

    free(count); // Free allocated memory
    return countOp;
}

int main() {
    int nums[] = {3, 1, 3, 4, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 6;

    int result = maxOperations(nums, numsSize, k);
    printf("Maximum number of operations: %d\n", result);

    return 0;
}