import java.util.*;
public class CountVowels {
    public static int count(String str) {
        if (str == null) return 0;
        String vowels = "aeiou";
        // HashSet<Character> set = new HashSet<>();
        // for (var ch : vowels.toCharArray()) {
        //     set.add(ch);
        // }
        int count = 0;
        for (var ch : str.toCharArray()) {
            // if (set.contains(ch)) {
            //     count++;
            // }
            if (vowels.indexOf(ch) != -1) {
                count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        String str = "aeiouxyz";
        System.out.println("total number of vowels in the string are: " + count(str));
    }
}
