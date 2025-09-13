
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head; // base case

        // Dummy nodes for 0s, 1s, and 2s
        ListNode *zeroDummy = new ListNode(-1);
        ListNode *oneDummy = new ListNode(-1);
        ListNode *twoDummy = new ListNode(-1);

        // Tails for the three lists
        ListNode *zero = zeroDummy, *one = oneDummy, *two = twoDummy;

        // Traverse and separate nodes
        ListNode *curr = head;
        while (curr) {
            if (curr->val == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->val == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Connect the lists
        zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
        one->next = twoDummy->next;
        two->next = nullptr;

        // New head
        ListNode *newHead = zeroDummy->next;

        // Cleanup dummy nodes
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;

        return newHead;
    }
};
