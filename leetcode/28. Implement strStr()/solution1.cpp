class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        if (needle.size() == 0) {
            return 0;
        }
        
        if (haystack.size() == 0) {
            return -1;
        }
        
        
        for (int i = 0; i < haystack.size(); ++i) {
            if (haystack.size() - i < needle.size()) {
                return -1;
            }
            
            if (haystack[i] == needle[0]) {
                if (needle.size() == 1) {
                    return i;
                }
                int j = 1;
                
                bool flag = true;
                
                while (j < needle.size()) {
                    
                    if (i + j >= haystack.size()) {
                        flag = false;
                        break;
                    }
                    
                    if (needle[j] != haystack[i + j]) {
                        flag = false;
                        break;
                    }
                    
                    j += 1;
                }
                
                if (flag) {
                    return i;
                }
            }
        }
        
        return -1;
        
    }
};
