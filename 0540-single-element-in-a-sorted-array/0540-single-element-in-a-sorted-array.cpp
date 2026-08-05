class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        
        // Edge cases for array length 1 or boundary elements
        if (n == 1) return A[0];
        if (A[0] != A[1]) return A[0];
        if (A[n - 1] != A[n - 2]) return A[n - 1];

        // Search within range [1, n - 2] to safely check mid-1 and mid+1
        int st = 1, end = n - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If mid is not equal to left or right neighbor, it's the single element
            if (A[mid] != A[mid - 1] && A[mid] != A[mid + 1]) {
                return A[mid];
            }

            // Check pattern: Even index pair should match (even, odd) -> (i, i+1)
            if ((mid % 2 == 1 && A[mid] == A[mid - 1]) || (mid % 2 == 0 && A[mid] == A[mid + 1])) {
                // Single element lies on the right half
                st = mid + 1;
            } else {
                // Single element lies on the left half
                end = mid - 1;
            }
        }

        return -1;
    }
};