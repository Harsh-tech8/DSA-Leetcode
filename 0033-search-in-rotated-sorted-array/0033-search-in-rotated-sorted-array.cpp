class Solution {
public:
    int search(vector<int>& A, int target) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= target && target < A[mid]) {
                    end = mid - 1; // Search left
                } else {
                    st = mid + 1;  // Search right
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                if (A[mid] < target && target <= A[end]) {
                    st = mid + 1;  // Search right
                } else {
                    end = mid - 1; // Search left
                }
            }
        }

        return -1;
    }
};