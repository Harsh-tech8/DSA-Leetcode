class Solution {
public:
    bool ispalin(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s2 == s;
    }
    void getpalin (vector<vector<string>> &ans,vector<string> &partition,string s){
        if (s.empty()){
            ans.push_back(partition);
            return;

        }
        for (int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);

            if(ispalin(part)){
                partition.push_back(part);
                getpalin(ans,partition,s.substr(i+1));
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getpalin(ans,partition,s);

        return ans;
    }
};