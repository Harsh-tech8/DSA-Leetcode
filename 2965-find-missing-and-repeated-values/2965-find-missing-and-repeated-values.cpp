class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        vector<int> ans; 
        unordered_set<int> s; 
        int n = arr.size(); 
        int a, b; 
        long long expsum = 0, actualsum = 0; 
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                actualsum += arr[i][j]; 
                if(s.find(arr[i][j]) != s.end()) {
                    a = arr[i][j]; 
                    ans.push_back(a); 
                } 
                s.insert(arr[i][j]); 
            } 
        } 
        
        expsum = (n*n) * (n*n + 1) / 2;
        b = expsum + a - actualsum; 
        
        ans.push_back(b); // Changed from ans.insert(b) to ans.push_back(b)
        return ans; 
    }
};