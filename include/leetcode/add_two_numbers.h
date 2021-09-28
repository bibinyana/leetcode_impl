#pragma once

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNumbers {
  int increment_to_next(ListNode* &l) {
    int x = 0;
    if (l != nullptr) {
      x = l->val;
      l = l->next;
    }
    return x;
  }

public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    int sum = 0;
    ListNode* sum_list = nullptr;
    ListNode** track_sum_list = &sum_list;

    while (l1 != nullptr || l2 != nullptr) {
      int x = increment_to_next(l1);
      int y = increment_to_next(l2);
      sum = x + y + carry;
      ListNode* node = new ListNode(sum % 10);
      *track_sum_list = node;
      track_sum_list = (&node->next);
      carry = sum / 10;
    }
    if (carry > 0) {
      ListNode* node = new ListNode(carry % 10);
      *track_sum_list = node;
    }
    return sum_list;
  }
};