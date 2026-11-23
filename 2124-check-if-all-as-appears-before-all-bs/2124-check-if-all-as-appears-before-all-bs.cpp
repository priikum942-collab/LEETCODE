class Solution {
public:
    bool checkString(string s) {
        string temp = s;

        sort(temp.begin(),temp.end());

        if(temp == s)
        {
            return true;
        }

        return false;
    }
};