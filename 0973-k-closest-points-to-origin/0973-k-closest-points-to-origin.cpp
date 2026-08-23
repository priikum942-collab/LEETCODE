class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,pair<int,int>>>pq; // max- heap

        for(int i=0;i<n;i++)
        {
            int sqr_dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({sqr_dist,{points[i][0],points[i][1]}});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int point1 = top.second.first;
            int point2 = top.second.second;
            ans.push_back({point1,point2});
        }

        return ans;
    }
};