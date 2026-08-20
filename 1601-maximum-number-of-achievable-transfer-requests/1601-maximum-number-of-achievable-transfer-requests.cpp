class Solution {
public:

    int solve( vector<vector<int>>& requests,int n, vector<int>&temp,int ind,int count)
    {
        int m = requests.size();
        if(ind == m)
        {
            for(int i=0;i<n;i++)
            {
                if(temp[i]!=0)
                {
                    return -1e9;
                }
            }

            return count;
        }

        //take
        int from = requests[ind][0];
        int to = requests[ind][1];

        temp[from] -= 1;
        temp[to] += 1;
  

        int take = solve(requests,n,temp,ind+1,count+1);

        temp[from] += 1;
        temp[to] -= 1;
        

        //not take
        int not_take = solve(requests,n,temp,ind+1,count);


        return max(take,not_take);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>temp(n,0);

        return solve(requests,n,temp,0,0);
    }
};