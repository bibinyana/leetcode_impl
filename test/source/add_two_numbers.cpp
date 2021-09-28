#include "leetcode/add_two_numbers.h"

#include <vector>

#include "gtest/gtest.h"

ListNode* CreateListFromVector(std::vector<int> data) {
  ListNode* node;
  ListNode** track_node = &node;
  for (auto a : data) {
    *track_node = new ListNode(a);
    track_node = &(node->next);
  }
  return node;
}

void DeleteVector(ListNode* node) {
  ListNode* n = nullptr;
  while (node != nullptr) {
    n = node;
    node = node->next;
    delete n;
  }
}

std::vector<int> ConvertToVector(ListNode* node) {
  std::vector<int> output;
  while (node != nullptr) {
    output.push_back(node->val);
    node = node->next;
  }
  return output;
}

TEST(TestAddTwoNumbers, Test1) {
  std::vector<int> input1 = {2, 4, 3};
  std::vector<int> input2 = {5, 6, 4};
  std::vector<int> expected_output = {7, 0, 8};
  ListNode* list1 = CreateListFromVector(input1);
  ListNode* list2 = CreateListFromVector(input2);

  AddTwoNumbers add_nums;
  ListNode* output_list = add_nums.addTwoNumbers(list1, list2);
  ListNode** track_list = &output_list;
  auto output_vector = ConvertToVector(output_list);
//   EXPECT_EQ(output_vector.size(), input1.size());

//   EXPECT_EQ(output_vector[0], 7);
//   EXPECT_EQ(output_vector[1], 0);
//   EXPECT_EQ(output_vector[2], 8);
  //   EXPECT_TRUE(std::equal(std::begin(output_vector), std::end(output_vector),
  //                          std::begin(expected_output), std::end(expected_output)));

  DeleteVector(list1);
  DeleteVector(list2);
}