#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* head = temp;
    int carry = 0;

    // Adding elements from both lists while they are not null
    while (l1 != NULL || l2 != NULL) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Setting carry and node value
        carry = sum / 10;
        temp->val = sum % 10;

        // Allocating next node if there are more elements to process
        if (l1 != NULL || l2 != NULL) {
            temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            temp = temp->next;
        } else {
            temp->next = NULL;
        }
    }

    // If there is a carry remaining, add a new node for it
    if (carry > 0) {
        temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        temp = temp->next;
        temp->val = carry;
        temp->next = NULL;
    }

    return head;
}
