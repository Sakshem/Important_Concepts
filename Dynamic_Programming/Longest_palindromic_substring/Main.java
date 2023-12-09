
// package Dynamic_Programming.Longest_palindromic_substring;
import java.util.*;

public class Main {

  public static void main(String[] args) {
    String s = "aaaabbaa";
    String ans = longestPalindrome(s);
    System.out.println("Longest Palindrome: " + ans);
  }

  public static String longestPalindrome(String s) {
    int length = s.length();
    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
      int len1 = expand(i, i, s);
      int len2 = expand(i, i + 1, s);
      int len = Math.max(len1, len2);
      if (len > end - start) {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }
    return s.substring(start, end + 1);
  }

  public static int expand(int left, int right, String s) {
    while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
      left--;
      right++;
    }
    return right - left - 1;
  }
}
