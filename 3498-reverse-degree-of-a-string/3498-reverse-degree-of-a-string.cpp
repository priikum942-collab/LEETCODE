class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            int num = 26 - (s[i]-'a');
            sum += num*(i+1);
        }

        return sum;
    }
};