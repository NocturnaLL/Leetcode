class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp1 = head;
        ListNode* templeft = nullptr;
        ListNode* tempright = nullptr;
        while(temp1!=NULL){
            if(left == temp1->val || right == temp1->val){
                if(left == temp1->val){
                    templeft = temp1;
                }
                if(right == temp1->val){
                    tempright = temp1;
                }
            }
 
            temp1 = temp1->next;
        }
        if(templeft!=nullptr && tempright!=nullptr){
            int copy = templeft->val;
            templeft->val = tempright->val;
            tempright->val = copy;
        }
        return head;
    }
};