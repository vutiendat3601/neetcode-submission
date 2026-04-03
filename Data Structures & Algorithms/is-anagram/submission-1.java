class Solution {
  public boolean isAnagram(String s, String t) {
    int n = 0;
    if ((n = s.length()) != t.length()) {
      return false;
    }
    int[] cntS = new int[128];
    int[] cntT = new int[128];
    for (int i = 0; i < n; i++) {
      cntS[s.charAt(i)]++;
      cntT[t.charAt(i)]++;
    }
    for (int i = 97; i <= 122; i++) {
      if (cntS[i] != cntT[i]) {
        return false;
      }
    }
    return true;
  }
}
