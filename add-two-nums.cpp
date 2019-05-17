#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode *l2)
{
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    int carry_bit = 0;
    while (l1 || l2)
    {
        int sum = ((l1)?(l1->val):0) + ((l2)?(l2->val):0) + carry_bit;
        current->next = new ListNode(sum%10);
        carry_bit = sum / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        current = current->next;
    }
    if (carry_bit) current->next = new ListNode(carry_bit);
}

int main(void)
{
    return 0;
}
