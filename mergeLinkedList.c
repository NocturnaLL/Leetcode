struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* head=temp;
    while(list1!=NULL && list2!=NULL){
        if(list1->val>list2->val){
        temp->val=list2->val;
        temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        temp=temp->next;
        list2=list2->next;
        }
        else if(list1->val<=list2->val){
        temp->val=list1->val;
        temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        temp=temp->next;
        list1=list1->next;
        }
    }
    while (list1 != NULL) {
        temp->val = list1->val;
        list1 = list1->next;
        if (list1 != NULL) {
            temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            temp = temp->next;
        }
    }

    // Add remaining elements from list2
    while (list2 != NULL) {
        temp->val = list2->val;
        list2 = list2->next;
        if (list2 != NULL) {
            temp->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            temp = temp->next;
        }
    }
    temp->next = NULL;
    return head;
}