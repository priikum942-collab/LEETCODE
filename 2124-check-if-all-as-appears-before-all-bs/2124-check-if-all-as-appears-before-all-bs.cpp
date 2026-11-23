class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        for(int i=0;i<n-1;i++)
        {
            string temp;
            temp += s[i];
            temp += s[i+1];
            if(temp == "ba")
            {
                return false;
            }
        }

        return true;
    }
};