class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // stores indices
        
        // 1. Process the first window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        // 2. Process the remaining windows
        for (int i = k; i < nums.size(); i++) {
            // Push the maximum of the previous window
            ans.push_back(nums[dq.front()]);
            
            // Remove elements that are out of the current window (index <= i - k)
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove smaller elements from the back to maintain decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        // Push the maximum for the very last window
        ans.push_back(nums[dq.front()]);
        
        return ans;
    }
};