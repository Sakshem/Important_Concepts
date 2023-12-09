import java.util.*;
public class RemoveDuplicates {
    public static String remove(String str) {
        if (str == null) return "";
        StringBuilder output = new StringBuilder();
        HashSet<Character> seen = new HashSet<>();
        for (char ch : str.toCharArray()) {
            if (!seen.contains(ch)) {
                seen.add(ch);
                output.append(ch);
            }
        }
        return output.toString();
    }
    public static void main(String[] args) {
        String s = "aabdcdede";
    
        System.out.println(remove(s));
        // output: abdce
    }
}
