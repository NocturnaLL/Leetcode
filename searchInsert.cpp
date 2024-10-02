   searchInsert
   
    if (target > nums.back()) return nums.size(); 
    if (target < nums.front()) return 0;
    
    int low = 0;
    int high = nums.size() - 1;
    
    while (low <= high) { 
        int mid = low + (high - low) / 2; // Avoid potential overflow
        
        if (nums[mid] == target) {
            return mid; 
        } else if (nums[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    

    int searchInsert(int* nums, int numsSize, int target) {
    int* left = nums;
    int* right = nums + numsSize - 1;

    while (left <= right) {
        int* mid = left + (right - left) / 2;

        if (*mid == target) {
            return mid - nums; // Return the index by subtracting the base address
        } else if (*mid > target) {
            right = mid - 1; // Move the right pointer to the position before mid
        } else {
            left = mid + 1; // Move the left pointer to the position after mid
        }
    }

    return left - nums; // If not found, return the position where it should be inserted
}

    
    return low;