
class Solution {
    public String removeDuplicates(String s) {

        StringBuilder t = new StringBuilder();
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (t.length() > 0 && t.charAt(t.length() - 1) == s.charAt(i)) {
                t.deleteCharAt(t.length() - 1);
            }
            else {
                t.append(s.charAt(i));
            }
        }

        return t.toString();
    }
}
