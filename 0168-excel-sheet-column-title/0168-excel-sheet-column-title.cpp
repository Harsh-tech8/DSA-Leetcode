class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // Adjust for 1-based indexing
            int remainder = columnNumber % 26;
            result += (char)('A' + remainder);
            columnNumber /= 26;
        }
        
        // The characters were added in reverse order (least significant to most)
        reverse(result.begin(), result.end());
        return result;
    }
};