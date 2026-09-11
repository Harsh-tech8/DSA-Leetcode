class Solution {
private:
    void getCombinationSum(std::vector<int>& arr, int idx, int tar, std::vector<std::vector<int>>& ans, std::vector<int>& combin) {
        // Base case: if target is 0, we found a valid combination
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }
        
        // Base case: if target becomes negative or we have gone past the last index
        if (tar < 0 || idx == arr.size()) {
            return;
        }
        
        // Option 1: Include the current element (can be chosen multiple times, so index remains 'idx')
        combin.push_back(arr[idx]);
        getCombinationSum(arr, idx, tar - arr[idx], ans, combin);
        combin.pop_back(); // Backtrack
        
        // Option 2: Exclude the current element and move to the next index
        getCombinationSum(arr, idx + 1, tar, ans, combin);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& arr, int tar) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combin;
        getCombinationSum(arr, 0, tar, ans, combin);
        return ans;
    }
};