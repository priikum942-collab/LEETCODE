class Solution {
public:
vector<vector<string>>ans;
    void solve(string &s,int n,int ind,vector<vector<string>>&ans,vector<string>&temp)
    {
        //base-case
        if(ind == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int k=ind;k<n;k++)
        {
            int i = ind;
            int j = k;
            bool val = true;


            while(i<=j)
            {
                if(s[i]!=s[j])
                {
                    val = false;
                    break;
                }
                i++;
                j--;
            }

            if(val)
            {
                temp.push_back(s.substr(ind, k - ind + 1));
                solve(s,n,k+1,ans,temp);
                temp.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
       int n = s.size();
       vector<string>temp;
       
       solve(s,n,0,ans,temp); 
       return ans;
    }
};