class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map <char, vector<char>> charmap;
        
        vector <string> ret;
        
        if (digits == "") {
            return ret;
        }
        
        char start = 'a';
        
        for (char i = '2'; i <= '9'; ++i) {
            int count = 3;
            
            if (i == '7' || i == '9') {
                count = 4;
            }
            
            while (count--) {
                charmap[i].push_back(start);
                start += 1;
            }
        }
        
        // Charmap created here
        
        string current_output;
        vector<int> current_pos;
        
        int curr_length = digits.size();
        
        for (int i = 0; i < digits.size(); ++i) {
            current_pos.push_back(0);
            current_output.push_back(charmap[digits[i]][0]);
        }
        
        ret.push_back(current_output);
        
        while (1) {
            int pointer = current_output.size() - 1;
            bool flag = false;
            
            current_pos[pointer] += 1;
            
            while (current_pos[pointer] == charmap[digits[pointer]].size()) {
                
                pointer -= 1;
                
                if (pointer < 0) {
                    flag = true;
                    break;
                }
                
                current_pos[pointer] += 1;
            }
            
            if (flag) {
                break;
            }
            
            current_output[pointer] = charmap[digits[pointer]][current_pos[pointer]];
            
            for (pointer += 1; pointer < current_output.size(); ++pointer) {
                current_pos[pointer] = 0;
                current_output[pointer] = charmap[digits[pointer]][0];
            }
            
            ret.push_back(current_output);
        }
        
        return ret;
    }
};
