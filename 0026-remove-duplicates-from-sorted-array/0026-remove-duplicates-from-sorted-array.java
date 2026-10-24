class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        int[] count = new int[201];

        // Count frequency 
        for (int i = 0; i < nums.length; i++) {
            int index = nums[i] + 100;
            count[index]++;
        }

        int j = 0;

        // Store unique elements 
        for (int i = 0; i < 201; i++) {
            if (count[i] != 0) {
                int ogdigit = i - 100;
                nums[j] = ogdigit;
                j++;
            }
        }

        int size = j;

        return size;
    }
}