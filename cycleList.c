#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with a cycle based on the given pos
struct ListNode* createLinkedListWithCycle(int* arr, int arrSize, int pos) {
    if (arrSize == 0) {
        return NULL;
    }

    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    struct ListNode* cycleNode = NULL;

    if (pos == 0) {
        cycleNode = head;
    }

    // Create the linked list
    for (int i = 1; i < arrSize; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
        if (i == pos) {
            cycleNode = current;
        }
    }

    // Create the cycle if pos is not -1
    if (pos != -1) {
        current->next = cycleNode;
    }

    return head;
}

// Function to detect if the linked list has a cycle
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // If the list is empty or has only one element, there can't be a cycle
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer by one step
        fast = fast->next->next;     // Move fast pointer by two steps

        if (slow == fast) {
            return true; // If the slow pointer and fast pointer meet, there is a cycle
        }
    }

    return false; // If we reach the end of the list, there is no cycle
}

int main() {
    int arr[] = {3, 2, 0, -4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int pos = 1;  // Creating a cycle that points to index 1

    struct ListNode* head = createLinkedListWithCycle(arr, arrSize, pos);
    bool result = hasCycle(head);
    if (result) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }

    return 0;
}
