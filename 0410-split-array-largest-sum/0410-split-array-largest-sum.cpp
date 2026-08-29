class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;

        // Find minimum possible answer and maximum possible answer
        for (int num : nums) {
            start = max(start, num);
            end += num;
        }

        int answer = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            int currentSum = 0;
            int subarrays = 1;

            // Check how many subarrays are needed
            // if maximum allowed sum is mid
            for (int num : nums) {

                if (currentSum + num <= mid) {
                    currentSum += num;
                }
                else {
                    subarrays++;
                    currentSum = num;
                }
            }

            // Too many subarrays
            if (subarrays > k) {
                start = mid + 1;
            }

            // mid is possible
            else {
                answer = mid;
                end = mid - 1;
            }
        }

        return answer;
    }
};