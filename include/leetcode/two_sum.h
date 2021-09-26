#pragma once
#include <unordered_map>
#include <vector>

/// Brief Given an array of integers nums and an integer target, return indices of the two numbers
/// such that they add up to target.
class TwoSum {
public:
  /// Brief Returns vector of indices that sums to target.
  /**
   * \param[in] nums Array of integers, sorted or unsorted.
   * \param[in] target Target number to which integers should add upto.
   *  \return vector of indices for a solution, empty if no solution.
   */
  std::vector<int> calSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> track_residual;
    std::vector<int> results;
    for (auto i = 0; i < nums.size(); ++i) {
      if (track_residual.find(nums[i]) == track_residual.end()) {
        track_residual[target - nums[i]] = i;
      } else {
        results.push_back(track_residual[nums[i]]);
        results.push_back(i);
        break;
      }
    }
    return results;
  }
};