class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() >k)
        {
            int n = s.size();
            string temp ="";
            for(int i=0;i<n;)
            {
                int sum = 0;
                for(int j= 0;j<k && i<n;j++)
                {
                    sum +=s[i] -'0';
                    i++;
                }
                temp += to_string(sum);
            }
            s = temp;
        }

        return s;
    }
};