class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                seen.erase(num);
            } else {
                seen.insert(num);
            }
        }
        
        return *seen.begin();
    }
};