class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftsum = 0;
        int rightsum = 0;
        int leftcount = 0;
        int rightcount = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftcount++;
            }
            else
            {
                leftsum += num[i] - '0';
            }
        }

        for (int i = n - 1; i >= n / 2; i--) {
            if (num[i] == '?') {
                rightcount++;
            }
            else
            {
                rightsum += num[i] - '0';
            }
        }

        // if ((leftcount + rightcount) == 0) {
        //     return false;
        // }

        // odd no. of q mark
        if ((leftcount + rightcount) % 2 != 0) {
            return true;
        }

        if ((2 * rightsum + 9 * rightcount) == (2 * leftsum + 9 * leftcount)) {
            return false;
        }

        return true;
    }
};