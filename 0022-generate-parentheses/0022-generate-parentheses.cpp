class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (st.empty()) {
                return false;
            } else if (s[i] == ')' && st.top() == '(' ) {
                st.pop();
            } else {
                return false;
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
    void solve(int n, vector<string>& ans, string temp) {
        // base case
        if (temp.size() == 2 * n) {
            if (isValid(temp)) {
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        solve(n, ans, temp);
        temp.pop_back();

        temp.push_back(')');
        solve(n, ans, temp);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";

        vector<string> ans;

        solve(n, ans, "");

        return ans;
    }
};