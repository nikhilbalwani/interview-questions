#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, string::iterator> last_occurred;
        int max_val = 1;
        
        if (s.size() == 0) {
            return 0;
        }
        
        for (string::iterator end = s.begin(), start = s.begin(); end != s.end(); ++end) {
            
            char ele = *end;
            
            // If the element has occurred before
            if (last_occurred.find(ele) != last_occurred.end()) {
                string::iterator last_occurred_pos = last_occurred[ele];
                last_occurred_pos += 1;
                
                start = max<string::iterator> (last_occurred_pos, start);
            }
            
            last_occurred[ele] = end;
            
            max_val = max<int> (max_val, int(end - start) + 1 );
        }
        
        return max_val;
    }
};
