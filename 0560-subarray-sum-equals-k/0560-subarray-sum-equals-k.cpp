class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        int currentSum = 0;
        int count = 0;
        
     
        prefixSumFreq[0] = 1;
        
        for (int num : nums) {
            currentSum += num;
            
            int target = currentSum - k;
            if (prefixSumFreq.find(target) != prefixSumFreq.end()) {
                count += prefixSumFreq[target];
            }
            

            prefixSumFreq[currentSum]++;
        }
        
        return count;
    }
};