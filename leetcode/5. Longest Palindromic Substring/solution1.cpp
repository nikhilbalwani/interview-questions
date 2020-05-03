#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    inline bool next_left_span_valid(int i, int palindrome_len, string s) {
        return ( i - palindrome_len - 1 ) >= 0;
    }
    
    inline bool next_right_span_valid(int i, int palindrome_len, string s) {
        return ( i + palindrome_len + 1 ) < s.size();
    }
    
    string longestPalindrome(string s) {
        
        int c = 0, r = 0, palindrome_len, max_p, max_i;
        
        string s2(2 * s.size() + 1, '*');
        
        for (int i = 0; i < s.size(); ++i) {
            s2[2 * i + 1] = s[i];
        }
        
        s = s2;
        
        vector <int> p(s.size(), 0);
        
        for (int i = 0; i < s.size(); ++i) {
            
            // If index i is in the boundary of current most right spanning palindrome
            if (i <= r) {
                // Look at the mirror 2 * c - i
                int mirror_len = p[2 * c - i];
                
                // r - i
                int minimum_possible_len = r - i;
                
                // Take the minimum of both, minimum_possible_len will be selected only
                // when mirror_len spans out of the current most right spanning palindrome
                
                palindrome_len = min(mirror_len, minimum_possible_len);
            }
            
            // If the index exceeds the boundary
            else {
                
                // There is no way to infer from mirror, as mirror does not exist at the moment
                palindrome_len = 0;
            }
            
            while (next_left_span_valid(i, palindrome_len, s) 
                   && next_right_span_valid(i, palindrome_len, s)) {
                if (s[i - palindrome_len - 1] == s[i + palindrome_len + 1]) {
                    palindrome_len += 1;
                }
                else {
                    break;
                }
            }

            // Done expanding palidrome to its maximum length

            p[i] = palindrome_len;

            // Checking for the current most right spanning palindrome
            if (i + palindrome_len > r) {
                // Change the center c
                c = i;

                // Change the right index
                r = i + palindrome_len;
            }
            
            // Done expanding palidrome to its maximum length

            p[i] = palindrome_len;

            // Checking for the current most right spanning palindrome
            if (i + palindrome_len > r) {
                // Change the center c
                c = i;

                // Change the right index
                r = i + palindrome_len;
            }
            
            if (p[i] > max_p) {
                max_p = p[i];
                max_i = i;
            }
        }
        
        /*
        string ret = s.substr(max_i - max_p, 2 * max_p);
        ret.erase(remove(ret.begin(), ret.end(), '*'), ret.end());
        */
        
        string sub = s.substr(max_i - max_p, 2 * max_p);
        string ret = "";
        
        for (int i = 0; i < sub.size(); ++i) {
            if (sub[i] != '*') {
                ret.push_back(sub[i]);
            }
        }
        
        return ret;
    }
};
