class Solution {
public:
    
    bool is_right_bracket(char bracket) {
        return (bracket == ')' || bracket == ']' || bracket == '}');
    }
    
    char get_left_complement(char right_bracket) {
        if (right_bracket == '}') {
            return '{';
        }
        else if (right_bracket == ']') {
            return '[';
        }
        
        else if (right_bracket == ')') {
            return '(';
        }
        
        return ' ';
    }
    
    bool isValid(string s) {
        stack <char> check;
        
        for (int i = 0; i < s.size(); ++i) {
            if (is_right_bracket(s[i])) {
                char left_complement = get_left_complement(s[i]);
                
                if (check.size() != 0 and left_complement == check.top()) {
                    check.pop();
                    continue;
                }
            }
            
            check.push(s[i]);
            
        }
        
        return check.size() == 0;
    }
};
