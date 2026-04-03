class Solution {
  public boolean isPalindrome(String s) {
    final char[] chars = s.toCharArray();
    final StringBuilder sb = new StringBuilder();
    for (char c : chars) {
      if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
        sb.append(c);
      }
    }
    final String str = sb.toString();
    final String reversedStr = sb.reverse().toString();
    return str.equalsIgnoreCase(reversedStr);
  }
}
