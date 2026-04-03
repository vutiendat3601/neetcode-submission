class Solution {
  public int longestConsecutive(int[] nums) {
    final PriorityQueue<Integer> pq = new PriorityQueue<>((x, y) -> -Integer.compare(x, y));
    for (int num : nums) {
      pq.add(num);
    }
    int result = 0;
    int cnt = 0;
    int lastNum = Integer.MAX_VALUE;
    while (!pq.isEmpty()) {
      final int num = pq.poll();
      if (num == lastNum - 1) {
        cnt++;
        lastNum = num;
      } else if (num != lastNum) {
        lastNum = num;
        result = Math.max(cnt, result);
        cnt = 1;
      }
    }
    return Math.max(cnt, result);
  }
}
