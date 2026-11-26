class Solution {

    static int findPivotIndex(int[] nums) {
        int n = nums.length;
        int s = 0;
        int e = n - 1;

        if (nums[s] < nums[e]) {
            return -1;
        }

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] <= nums[n - 1]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return e;
    }

    static int binarySearch(int[] nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return -1;
    }

    public int search(int[] nums, int target) {
        int n = nums.length;

        int pivotIndex = findPivotIndex(nums);

        int s1 = 0;
        int e1;

        if (pivotIndex == -1) {
            e1 = -1;
        } else {
            e1 = pivotIndex;
        }

        int s2 = pivotIndex + 1;
        int e2 = n - 1;

        if (s1 <= e1 &&
                target >= nums[s1] &&
                target <= nums[e1]) {
            return binarySearch(nums, s1, e1, target);
        }

        if (s2 <= e2 &&
                target >= nums[s2] &&
                target <= nums[e2]) {
            return binarySearch(nums, s2, e2, target);
        }

        return -1;
    }
}