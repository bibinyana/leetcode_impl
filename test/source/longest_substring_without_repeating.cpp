#include <vector>
#include "leetcode/longest_substring_without_repeating.h"
#include "gtest/gtest.h"

TEST(TestLongestString, Test1){
    LongestSubstringWithoutRepeat obj;
    std::string input("abcabcbb");
    int output = 3;
    int max_len = obj.lengthOfLongestSubstring(input);
    EXPECT_EQ(max_len, output);
}

TEST(TestLongestString, Test2){
    LongestSubstringWithoutRepeat obj;
    std::string input("bbbbb");
    int output = 1;
    int max_len = obj.lengthOfLongestSubstring(input);
    EXPECT_EQ(max_len, output);
}