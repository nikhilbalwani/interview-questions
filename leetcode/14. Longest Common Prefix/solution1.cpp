class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int smallest_size = INT_MAX;
        int i, j;
        
        if (strs.size() == 0) {
            return "";
        }
        
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            
            smallest_size = min(smallest_size, (int) str.size() );
        }
        
        if (smallest_size == 0) {
            return "";
        }
        
        for (i = 0; i < smallest_size; ++i) {
            char c;
            bool flag = false;
            
            for (j = 0; j < strs.size(); ++j) {
                string str = strs[j];
                
                if (j == 0) {
                    c = str[i];
                }
                else {
                    if (c != str[i]) {
                        flag = true;
                        break;
                    }
                }
                
            }
            
            if (flag == true) {
                break;
            }
        }
        
        return strs[0].substr(0, i);
        
    }
};
