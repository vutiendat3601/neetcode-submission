class Solution {
  public int[] twoSum(int[] nums, int target) {
    int begin = 0, end = nums.length - 1;
    while (begin < end) {
      final int sum = nums[begin] + nums[end];
      if (sum == target) {
        return new int[] {begin + 1, end + 1};
      } else if (sum < target) {
        begin++;
      } else {
        end--;
      }
    }
    return new int[]{};
  }
}
