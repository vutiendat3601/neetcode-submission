class Solution {
  private  int[] indices = new int[11];

  public List<List<Integer>> subsets(int[] nums) {
      List<List<Integer>> res = new ArrayList<>();
      res.add(new ArrayList<>());
      for (int i = 0; i <= nums.length; i++) {
          indices[0] = -1;
          subsets(nums, res, i, 1);
      }
      return res;
  }

  public void subsets(int[] nums, List<List<Integer>> res, int n, int iTh) {
      for (int i = indices[iTh - 1] + 1; i < nums.length; i++) {
          indices[iTh] = i;
          if (iTh == n) {
              List<Integer> temp = new ArrayList<>();
              for (int k = 1; k <= n; k++) {
                  temp.add(nums[indices[k]]);
              }
              res.add(temp);
          } else {
              subsets(nums, res, n, iTh + 1);
          }
      }
  }
}
