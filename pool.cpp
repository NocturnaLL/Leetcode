#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        // Use two pointers starting from both ends of the array
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int levelWater = minHeight * (right - left);
            maxWater = max(maxWater, levelWater);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    // Example input
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Create an instance of Solution and call maxArea
    Solution solution;
    int result = solution.maxArea(height);

    // Print the result
    cout << "Maximum water contained: " << result << endl;

    return 0;
}
