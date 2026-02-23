//Given head, the head of a linked list, determine if the linked list has a cycle in it.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>

bool hasCycle(struct ListNode *head) {
    
    
    if (head == NULL || head->next == NULL)
        return false;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;    
        
        if (slow == fast)          
            return true;
    }
    
    return false;  
}
