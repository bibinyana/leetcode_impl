#pragma once

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class AddTwoNumbers {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int local_sum = 0;
    int carry = 0;
    int sum = 0;
    ListNode* sum_list = nullptr;
    ListNode** track_sum_list = &sum_list;

    auto increment_to_next = [&l1, &l2]() {
      int x = 0, y = 0;
      if (l1 != nullptr) {
        x = l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        y = l2->val;
        l2 = l2->next;
      }
      return x + y;
    };

    while (l1 || l2) {
      local_sum = increment_to_next();
      sum = local_sum + carry;
      ListNode* node = new ListNode(sum % 10);
      *track_sum_list = node;
      track_sum_list = &(node->next);
      carry = sum / 10;
    }
    if (carry > 0) {
      ListNode* node = new ListNode(carry % 10);
      *track_sum_list = node;
    }
    return sum_list;
  }
};