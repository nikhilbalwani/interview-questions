class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        unordered_map < char, string > hashmap;
        
        vector <string> ret;
        char current_char = 'a';
        
        if (digits.size() == 0) {
            return ret;
        }
        
        for (int i = 2; i < 10; ++i) {
            int letters_to_insert;
            
            if (i == 7 || i == 9) {
                letters_to_insert = 4;
            }
            else {
                letters_to_insert = 3;
            }
            
            while (letters_to_insert > 0) {
                
                hashmap[i + '0'].push_back(current_char);
                
                letters_to_insert -= 1;
                current_char += 1;
            }
        }
        
        explore_combinations(hashmap, "", digits, ret);
        
        
        return ret;
    }
    
    void explore_combinations(unordered_map <char, string> hashmap, string curr_string, string digits, vector <string> & ret) {
        int curr_len = curr_string.size();
        
        if (curr_len == digits.size()) {
            ret.push_back(curr_string);
            return;
        }
        
        string choices = hashmap[digits[curr_len]];
        
        for (int i = 0; i < choices.size(); ++i) {
            explore_combinations(hashmap, curr_string + choices[i], digits, ret);
        }
        
    }
};
