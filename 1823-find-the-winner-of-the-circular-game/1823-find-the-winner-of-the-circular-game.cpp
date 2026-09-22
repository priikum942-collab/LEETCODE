class Solution {
public:
    void solve(vector<int>&arr,int k,int i)
    {
        int n = arr.size();
        if(n==1)
        {
            return;
        }
        //find the idx to delete
        int idx = i + k - 1;
        //in circular way
        idx = idx % n;
        //delete
        arr.erase(arr.begin() + idx);
        //do it again until only 1 element is left
        solve(arr,k,idx);
    }
    int findTheWinner(int n, int k) {
        vector<int>arr(n);
        //fill the array
        for(int i=0;i<n;i++)
        {
            arr[i] = i+1;
        }
        
        solve(arr,k,0);

        return arr[0];
    }
};