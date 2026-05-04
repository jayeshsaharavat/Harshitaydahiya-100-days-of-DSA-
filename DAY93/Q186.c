
struct ListNode* insertionSortList(struct ListNode* head) {
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* nextNode = curr->next; 
        
        
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }
        
        
        curr->next = prev->next;
        prev->next = curr;
        
        
        curr = nextNode;
    }
    
    return dummy->next;
}
