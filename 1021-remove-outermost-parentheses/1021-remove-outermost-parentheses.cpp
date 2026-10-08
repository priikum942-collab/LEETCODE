class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                if (cnt > 0) {
                    ans.push_back(ch);
                }
                cnt++;
            } else {
                cnt--;
                if (cnt > 0) {
                    ans.push_back(ch);
                }
            }
        }

        return ans;
    }
};