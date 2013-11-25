#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL || m == n || m == 0)
            return head;
        int start = m < n? m - 1 : n - 1;
        int end = m > n? m - 1 : n - 1;
        ListNode *first, *pos1, *pos2, *last;
        
        int index = 0;
        if (start == 0) {
            pos2 = pos1 = head;
        } else {
            first = head;
            for (; index < start - 1; index++) {
                first = first->next;
                if (first == NULL)
                    return head;
            }
            pos1 = first->next;
            pos2 = first;
        }
        for (; index < end && pos2 != NULL; index++) {
            pos2 = pos2->next;
        }
        if (pos2 == NULL)
            return head;
        last = pos2->next;
        
        ListNode *prev = pos1, *cur = pos1->next, *next = cur->next;
        while(cur != pos2) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        if (start == 0)
            head = pos2;
        else
            first->next = pos2;
        pos1->next = last;
        
        return head;
    }
};

int main() {
    ListNode *head;
    int a[] = {1, 2, 3, 4, 5};
    head = new ListNode(0);
    ListNode *prev = head;
    Solution sol;
    for (int i = 0; i < 2; i++) {
        ListNode *new_node = new ListNode(a[i]);
        prev->next = new_node;
        prev = new_node;
    }
    head = sol.reverseBetween(head, 2, 3);
    ListNode *cur = head;
    while(cur) {
        cout << cur->val;
        cur = cur->next;
    }
    cout << endl;
}
