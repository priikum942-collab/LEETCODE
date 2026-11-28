import java.util.*;

class Solution {

    public int binarysearch(int nums[], int target, int s, int e) {

        // Base case
        if(s > e) {
            return -1;
        }

        int mid = s + (e - s) / 2;

        if(nums[mid] == target) {
            return mid;
        }

        else if(nums[mid] > target) {
            return binarysearch(nums, target, s, mid - 1);
        }

        else {
            return binarysearch(nums, target, mid + 1, e);
        }
    }

    public int search(int[] nums, int target) {

        int n = nums.length;

        int s = 0;
        int e = n - 1;

        int ans = binarysearch(nums, target, s, e);

        return ans;
    }
}