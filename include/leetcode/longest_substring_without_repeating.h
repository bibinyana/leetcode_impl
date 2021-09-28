#pragma once
#include <string>
#include <unordered_map>

class LongestSubstringWithoutRepeat {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> lookup_repeat;
    int repeated_string_index = -1;
    int string_max_len = 0;
    for (int i = 0; i < s.length(); ++i) {
      if ((lookup_repeat.find(s[i]) != lookup_repeat.end())
          && lookup_repeat[s[i]] > repeated_string_index) {
        repeated_string_index = lookup_repeat[s[i]];
      }
      if ((i - repeated_string_index) > string_max_len) {
        string_max_len = i - repeated_string_index;
      }
      lookup_repeat[s[i]] = i;
    }
    return string_max_len;
  }
};