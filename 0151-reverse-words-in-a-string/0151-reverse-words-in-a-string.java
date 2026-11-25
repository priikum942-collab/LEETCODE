class Solution {
    public String reverseWords(String s) {
        String ans = "";
        String word = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                word = s.charAt(i) + word;
            } 
            else if (!word.isEmpty()) {
                if (!ans.isEmpty()) {
                    ans += " ";
                }
                ans += word;
                word = "";
            }
        }

        if (!word.isEmpty()) {
            if (!ans.isEmpty()) {
                ans += " ";
            }
            ans += word;
        }

        return ans;
    }
}