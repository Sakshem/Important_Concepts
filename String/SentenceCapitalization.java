public class SentenceCapitalization {
    public static void main(String[] args) {
        String s = "the sky is blue in            color";
        System.out.println(capitalize(s));
    }

    public static String capitalize(String s) {
        if (s == null || s.trim().isEmpty()) return "";
        String[] words = s.trim().replaceAll(" +", " ").split(" ");
        for (int i = 0; i < words.length; i++) {
            words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1, words[i].length()).toLowerCase();
        }
        return String.join(" ", words).trim();
    }
}
