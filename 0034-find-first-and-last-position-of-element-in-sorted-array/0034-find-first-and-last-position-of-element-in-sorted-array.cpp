class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int start = 0;
        int end = nums.size() - 1;

        // Find first occurrence
        int first = -1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (target < nums[mid]) {
                end = mid - 1;
            }
            else if (target > nums[mid]) {
                start = mid + 1;
            }
            else if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            }
        }

        // Find last occurrence
        start = 0;
        end = nums.size() - 1;

        int last = -1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (target < nums[mid]) {
                end = mid - 1;
            }
            else if (target > nums[mid]) {
                start = mid + 1;
            }
            else if (nums[mid] == target) {
                last = mid;
                start = mid + 1;
            }
        }

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};