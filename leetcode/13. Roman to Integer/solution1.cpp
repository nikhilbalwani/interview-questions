class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val;
        int ret = 0;
        
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        
        if (s.size() == 1) {
            return val[s[0]];
        }
        
        for (int i = 0; i < s.size() - 1; ++i) {
            if ( val[s[i]] < val[s[i + 1]] ) {
                ret += (val[s[i + 1]] - val[s[i]]);
                i += 1;
            }
            else {
                ret += val[s[i]];
            }
        }
        
        if (val[s[s.size() - 2]] >= val[s[s.size() - 1]]) {
            ret += val[s[s.size() - 1]];
        }
        
        return ret;
    }
};
