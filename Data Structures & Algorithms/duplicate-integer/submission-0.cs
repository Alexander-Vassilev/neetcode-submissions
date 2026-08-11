public class Solution {
    public bool hasDuplicate(int[] nums) {
      List<int> seenList = new List<int>();

      for (int i = 0; i < nums.Length; i++) {
        if (seenList.Contains(nums[i])) {
            return true;
        } else {
            seenList.Add(nums[i]);
        }
      }

      return false;
    }
}
