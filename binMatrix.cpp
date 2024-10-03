class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Binary search to find the correct row
        int left = 0;
        int right = rows - 1;
        int midRow = 0;

        while (left <= right) {
            midRow = left + (right - left) / 2;
            int rowStart = matrix[midRow][0];
            int rowEnd = matrix[midRow][cols - 1];
            
            if (target == rowStart || target == rowEnd) {
                return true;  // If target matches the start or end of the row
            } else if (target < rowStart) {
                right = midRow - 1;  // Target must be in an earlier row
            } else if (target > rowEnd) {
                left = midRow + 1;  // Target must be in a later row
            } else {
                // Target is within the range of the current row
                break;
            }
        }

        // If we exit the loop, we should be in the correct row (midRow)
        // Binary search to find the correct column in the selected row
        int leftCol = 0;
        int rightCol = cols - 1;

        while (leftCol <= rightCol) {
            int midColumn = leftCol + (rightCol - leftCol) / 2;
            int columnVal = matrix[midRow][midColumn];

            if (target == columnVal) {
                return true;
            } else if (target < columnVal) {
                rightCol = midColumn - 1;
            } else {
                leftCol = midColumn + 1;
            }
        }

        // If target was not found in the column search, return false
        return false;
    }
};
