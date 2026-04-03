class Solution {
  public int maxArea(int[] heights) {
    int begin = 0;
    int end = heights.length -1;
    int max = 0;
    while (begin < end) {
      int area = end - begin;
      if (heights[begin] <= heights[end]) {
        area *= heights[begin];
        begin++;
      } else {
        area *= heights[end];
        end--;
      }
      if (max < area) {
        max = area;
      }
    }
    return max;
  }
}
