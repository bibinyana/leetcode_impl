#include "leetcode/two_sum.h"

#include "gtest/gtest.h"

TEST(TwoSumTest, TestEmptyInput) {
  TwoSum two_sum;
  std::vector<int> input;
  auto results = two_sum.calSum(input, 1);
  EXPECT_EQ(results.size(), 0);
}

TEST(twoSumTests, TestExample1) {
  TwoSum two_sum;
  std::vector<int> input = {3, 2, 4};
  std::vector<int> expected_results = {1, 2};
  auto results = two_sum.calSum(input, 6);
  EXPECT_TRUE(expected_results.size() == results.size()) << "Size: " << results.size();
  EXPECT_TRUE(std::equal(std::begin(expected_results), std::end(expected_results),
                         std::begin(results), std::end(results)));
}

TEST(twoSumTests, TestExample2) {
  TwoSum two_sum;
  std::vector<int> input = {2, 7, 11, 15};
  std::vector<int> expected_results = {0, 1};
  auto results = two_sum.calSum(input, 9);
  EXPECT_TRUE(expected_results.size() == results.size());
  EXPECT_TRUE(std::equal(std::begin(expected_results), std::end(expected_results),
                         std::begin(results), std::end(results)));
}