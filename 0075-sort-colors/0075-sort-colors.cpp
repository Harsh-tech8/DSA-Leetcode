class Solution {
public:
    void sortColors(vector<int>& A) {
        int n = A.size();

        int mid = 0,low = 0,high = n-1;

        while (mid <= high){
            if (A[mid] == 0){
                swap(A[low],A[mid]);
                mid++;low++;
            }

            else if (A[mid] == 1) mid++;

            else {//(A[mid] == 2)
                swap(A[high], A[mid]);
                high--;
            }

        }
    }
};