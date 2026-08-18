#define ll long long

class Solution {
public:
    int bulbSwitch(int n) {
        // unordered_map<ll,ll>mp;
        // for(ll i=1;i<=n;i++)
        // {
        //     mp[i]++;
        //     cout<<mp[i]<<" ";
        // }

        // for(ll i=2;i<=n;i++)
        // {
        //     for(auto &it : mp)
        //     {
        //         if(it.first % i == 0)
        //         {
        //             if(it.second == 0)
        //             {
        //                 it.second = 1;
        //             }
        //             else if( it.second == 1)
        //             {
        //                 it.second = 0;
        //             }
        //         }
        //     }
        // }

        // ll bulbs = 0;

        // for(auto it : mp)
        // {
        //     if(it.second == 1)
        //     {
        //         bulbs++;
        //     }
        // }

        // return (int)bulbs;

        return sqrt(n);
    }
};