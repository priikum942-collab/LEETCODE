class Solution {
public:
    int maxDepth(string s) {
        stack <int>st;
        int n = s.size();
        int cnt = 0;
        int max_cnt = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                cnt++;;
            }
            if(s[i]==')' && !st.empty() && st.top() == '(')
            {
                st.pop();
                cnt--;
            }
            max_cnt = max(max_cnt,cnt);
        }

        return max_cnt;
    }
};