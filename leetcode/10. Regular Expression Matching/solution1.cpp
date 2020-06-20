class Solution {
public:
    bool isMatch(string s, string p) {
        vector <string> wildcards;
        
        for (int i = 0; i < p.size(); ++i) {
            
            if (i < p.size() - 1 and p[i + 1] == '*') {
                wildcards.push_back(p.substr(i, 2));
                // cout << p.substr(i, 2) << endl;
                i += 1;
            }
            else {
                wildcards.push_back(p.substr(i, 1));
                // cout << p.substr(i, 1) << endl;
            }
        }
        
        bool dp[wildcards.size() + 1][s.size() + 1];
        
        dp[0][0] = true;
        
        for (int i = 1; i < s.size() + 1; ++i) {
            dp[0][i] = false;
        }
        
        for (int j = 1; j < wildcards.size() + 1; ++j) {
            dp[j][0] = dp[j - 1][0] && (wildcards[j - 1].size() == 2);
        }
        
        for (int i = 1; i < wildcards.size() + 1; ++i) {
            
            char c = wildcards[i - 1][0];
            for (int j = 1; j < s.size() + 1; ++j) {
                
                // * wildcard
                if (wildcards[i - 1].size() == 2) {
                    
                    if (c == '.') {
                        dp[i][j] = ( dp[i - 1][j - 1])
                                 || ( dp[i][j - 1])
                                 || dp[i - 1][j];    
                    }
                    else {
                        dp[i][j] = ( dp[i - 1][j - 1] && (c == s[j - 1]) )
                                 || ( dp[i][j - 1] && (c == s[j - 1]) )
                                 || dp[i - 1][j];
                    }
                }
                else {
                    if (c == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j - 1] && (c == s[j - 1]);
                    }
                }
            }
        }
        
        return dp[wildcards.size()][s.size()];
    }
};
