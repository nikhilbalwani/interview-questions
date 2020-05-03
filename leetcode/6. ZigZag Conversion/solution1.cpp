class Solution {
public:
    string convert(string s, int numRows) {
        string ret  = "";
        int sum = 2 * (numRows - 1);
        
        if (sum == 0) {
            return s;
        }
        
        for (int i = 0; i < min<int> (numRows, s.size()); ++i) {
            
            bool indicator = true;
            int alt1 = sum - 2 * i;
            int alt2 = 2 * i;
            int curr_index = i;
            
            ret += s[i];
            
            while (true) {
                if (indicator) {
                    curr_index += alt1;
                }
                else {
                    curr_index += alt2;
                }
                
                if (curr_index >= s.size()) {
                    break;
                }
                
                if ( (indicator && alt1) || (!indicator && alt2) ) {
                    ret += s[curr_index];
                }
                
                indicator = indicator ^ 1;
            }
        }
        
        
        return ret;
    }
};
