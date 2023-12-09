public class Rotations {
    public static boolean areRotations(String a, String b) {
        // if (a.length() != b.length()) {return false;}
        // if ((a + a).contains(b)) {
        //     return true;
        // }
        // return false;

        if (a == null || b == null) return false;
        return a.length() == b.length() && (a + a).contains(b);
    }
    public static void main(String[] args) {
        String a = "ABCD";
        // String b = "CDAB";
        String b = "CDBA";

        System.out.println(areRotations(a, b));
    }
}
