//Given the head of a singly linked list, the task is to remove a cycle if present.
//A cycle exists when a node's next pointer points back to a previous node, forming a loop. 
//Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. 
//The terminal will print true if a cycle is removed otherwise, it will print false.

/* structure of Node
struct Node {
    int data;
    Node* next;
};
*/

class Solution {
public:
    bool removeLoop(Node* head) {
        
        if (head == NULL || head->next == NULL)
            return false;

        Node *slow = head, *fast = head;

        // Step 1: Detect loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No loop found
        if (slow != fast)
            return false;

        // Step 2: Find start of loop
        slow = head;

        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove loop
        fast->next = NULL;

        return true;
    }
};
