import java.util.*;

class Solution {

    public boolean isSubsequence(String s, String t) {

        int n1 = s.length();
        int n2 = t.length();

        Stack<Character> st = new Stack<>();

        if(n1 == 0) {
            return true;
        }

        if(n2 == 0) {
            return false;
        }

        // Stack of t
        for(int i = 0; i < n2; i++) {
            st.push(t.charAt(i));
        }

        // Now compare
        int i = n1 - 1;

        while(!st.empty() && i >= 0) {

            if(s.charAt(i) == st.peek()) {

                st.pop();
                i--;
                continue;
            }

            st.pop();
        }

        if(i < 0) {
            return true;
        }

        return false;
    }
}