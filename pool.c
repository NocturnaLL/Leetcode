
#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int* left = height;
    int* right = height + heightSize - 1;  // Corrected to point to the last element
    int waterMax = 0;

    while (left < right) {
        int heightLevel;
        if (*left < *right)
            heightLevel = *left;
        else
            heightLevel = *right;

        int currentWater = heightLevel * (right - left);  // Distance between left and right pointers

        if (waterMax < currentWater)
            waterMax = currentWater;

        if (*left > *right)
            right--;
        else
            left++;
    }

    return waterMax;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, heightSize);
    printf("Maximum water contained: %d\n", result);

    return 0;
}
