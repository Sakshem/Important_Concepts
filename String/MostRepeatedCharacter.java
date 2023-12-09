import java.util.*;
public class MostRepeatedCharacter {
    private static char getMaxOccuringChar(String s) {
        if (s == null || s.isEmpty()) {
            return '\0'; // could throw an illegalArgumentException
        }
        Map<Character, Integer> map = new HashMap<>();
        for (var ch : s.toCharArray()) {
            if (map.containsKey(ch)) {
                map.replace(ch, map.get(ch) + 1);
            }
            else {
                map.put(ch, 1);
            }
        }
        int count = 0;
        char ans = '0';
        for (var entry : map.entrySet()) {
            if (entry.getValue() > count) {
                count = entry.getValue();
                ans = entry.getKey();
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        String s = "aaebcddeeedc";
        System.out.println("most repeated character in the string is: " + getMaxOccuringChar(s));
    }
}
