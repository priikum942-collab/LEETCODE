class Solution {
public:
    int maxi = INT_MIN;
    int mini = INT_MAX;

    void solve(vector<int>& cookies, int k,int n,int ind,int child,vector<int>&temp)
    {
        //if cookies are exhaust 
        if(ind>=n)
        {
           maxi = *max_element(temp.begin(), temp.end());
           mini = min(maxi,mini);
           return;
        }

        for(int i=0;i<k;i++)
        {
            temp[i]+=cookies[ind];
            solve(cookies,k,n,ind+1,i,temp);
            temp[i]-=cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int>temp(k,0);
        solve(cookies,k,n,0,0,temp);

        return mini;
    }
};