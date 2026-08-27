class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int i=0;
        int j= 0;
        int n = s.size();
        int cnt = 0;
        if(n == 0)
        {

        } 

        while(i<n && j<n)
        {
            while(i<n && s[i]=='0')
            {
                i++;
            }
            if(j<i)
            {
                j = i;
            }
            while(j<n && cnt < k )
            {
                if(s[j]=='1')
                {
                    cnt++;
                }
                j++;
            }

            if(cnt == k)
            {
                int len = j - i;
                string curr = s.substr(i, j - i);
                if(ans == "")
                {
                    ans = curr;
                }
                else if(len < ans.size())
                {
                    ans = curr;
                }
                else if(len == ans.size() && curr < ans)
                {
                    ans = curr;
                }
                if (s[i] == '1') {
                    cnt--;
                }

                i++;
            }
            // else {
            //     // Not enough 1s remaining
            //     break;
            // }
        }

        return ans;
    }
};