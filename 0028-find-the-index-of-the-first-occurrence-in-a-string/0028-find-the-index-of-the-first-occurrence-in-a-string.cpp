class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int ans = -1;
        bool found = false;
        if (m > n) {
            return ans;
        }

        for (int i = 0; i < n; i++) {
            ans = -1;
            if (s1[i] == s2[0]) {
                int start = 0;
                ans = i;
                int ind = i;
                found = true;
                while (start < m) {
                    if (s1[ind] != s2[start]) {
                        found = false;
                        break;
                    }
                    ind++;
                    start++;
                }
            }
            if (found) {
                return ans;
            }
        }

        return -1;
    }
};