#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_set <char> hashset;
        
        for (string::iterator end = s.begin(), start = s.begin(); end != s.end(); ++end) {
            char end_ele = *end;
            
            // If element is found
            if (hashset.find(end_ele) != hashset.end()) {
                
                while (*start != end_ele) {
                    hashset.erase(*start);
                    start += 1;
                }
                
                start += 1;
            }
            
            // If element is not found
            else {
                hashset.insert(end_ele);
            }
            
            max_len = max<int> (max_len, end - start + 1);
        }
        
        return max_len;
    }
};
