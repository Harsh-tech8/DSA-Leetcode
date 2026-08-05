class Solution {
public:
    int countRatioSubarrays(std::vector<int>& nums, int a, int b) {
        int n = nums.size();
        int valid_count = 0;

        for (int i = 0; i < n; ++i) {
            long long even_count = 0;
            long long odd_count = 0;

            for (int j = i; j < n; ++j) {
                if (nums[j] % 2 == 0) {
                    even_count++;
                } else {
                    odd_count++;
                }

                // Check condition: y > 0 and (x / y) <= (a / b)
                if (odd_count > 0 && even_count * b <= (long long)a * odd_count) {
                    valid_count++;
                }
            }
        }

        return valid_count;
    }
};