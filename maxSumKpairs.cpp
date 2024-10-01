#include <unordered_map>
#include <vector>
using namespace std;

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
        int numOp = 0;
        unordered_map<int, int> umap;

        // Count the occurrences of each number
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }

        // Find pairs
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = k - num;

            // Check if both num and its complement are available
            if (umap[num] > 0 && umap[complement] > 0) {
                if (num == complement) {
                    // If num and complement are the same, there should be at least two instances
                    if (umap[num] >= 2) {
                        numOp++;
                        umap[num] -= 2;
                    }
                } else {
                    // If num and complement are different
                    numOp++;
                    umap[num]--;
                    umap[complement]--;
                }
            }
        }
        return numOp;
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
