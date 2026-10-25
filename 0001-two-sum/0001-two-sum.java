class Solution {
    public int[] twoSum(int[] nums, int target) {

        int n = nums.length;
        int []ans = new int[] {-1,-1};
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {

            int req = target - nums[i];

            if (mp.containsKey(req)) {
               ans[0] = mp.get(req);
               ans[1] = i ;
            }

            mp.put(nums[i], i);
        }

        return ans;
    }
}
