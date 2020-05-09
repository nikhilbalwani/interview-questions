class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0) {
            return "";
        }
        else if (strs.size() == 1) {
            return strs[0];
        }
        
        string common = strs[0], curr_common;
        
        strs.erase(strs.begin());
        
        for (string str: strs) {
            
            int limit = min(str.size(), common.size());
            curr_common = "";
                
            for (int i = 0; i < limit; ++i) {
                if (str[i] == common[i]) {
                    curr_common += str[i];
                }
                else {
                    break;
                }
            }
            
            if (curr_common == "") {
                return "";
            }
            
            common = curr_common;
        }
        
        return common;
    }
};
