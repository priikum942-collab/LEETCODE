class Solution {
public:
    int max_len = 0;

    void solve(int index, string temp, vector<string>& arr) {
        // Update maximum
        max_len = max(max_len, (int)temp.size());

        for (int i = index; i < arr.size(); i++) {
            string newTemp = temp + arr[i];

            // Check duplicates
            unordered_set<char> st(newTemp.begin(), newTemp.end());

            if (st.size() == newTemp.size()) {
                solve(i + 1, newTemp, arr);
            }
        }
    }

    int maxLength(vector<string>& arr) {
        string temp = "";

        solve(0, temp, arr);

        return max_len;
    }
};