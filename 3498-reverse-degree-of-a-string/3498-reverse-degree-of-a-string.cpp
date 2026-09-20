class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            int num = ('z'-s[i])+1;
            sum += num*(i+1);
        }

        return sum;
    }
};