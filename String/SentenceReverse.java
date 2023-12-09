import java.util.*;
public class SentenceReverse {
    public static void reverseString(String str) {
        String[] words = str.trim().split(" ");

        StringBuilder reverseSentence = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            reverseSentence.append(words[i]);
            if (i != 0) reverseSentence.append(" ");
        }
        System.out.println(reverseSentence.toString());

        // OR another method

        Collections.reverse(Arrays.asList(words));
        String ans = String.join(" ", words);
        System.out.println(ans);
    }
    public static void main(String[] args) {
        String str = "the trees are green";
        reverseString(str);
    }
}
