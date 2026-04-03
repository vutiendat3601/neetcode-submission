class Solution {
  private final int MAX_N = 20_000;

  static class Pair {
    int value;
    int count;

    public Pair() {}

    public Pair(int value, int count) {
      this.value = value;
      this.count = count;
    }

    @Override
    public String toString() {
      return "Value: " + value + ", count: " + count;
    }
  }

  public int[] topKFrequent(int[] nums, int k) {
    final int[] result = new int[k];
    PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> -Integer.compare(p1.count, p2.count));
    final int[] cnts = new int[MAX_N + 1];
    for (int num : nums) {
      final int idx = num + MAX_N / 2;
      cnts[idx]++;
      pq.add(new Pair(num, cnts[idx]));
    }
    final Set<Integer> numSet = new HashSet<>();
    for (int i = 0; i < result.length; i++) {
      while (numSet.contains(pq.peek().value)) {
        pq.poll();
      }
      int value = pq.poll().value;
      result[i] = value;
      numSet.add(value);
    }
    return result;
  }
}
