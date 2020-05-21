class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> record;
        
        if (n == 0) {
            return record;
        }
        
        else if (n == 1) {
            return {"()"};
        }
        
        backtrack(record, 0, "", 2 * n);
        
        return record;
    }
    
    void backtrack(vector<string> &record, int curr_balance, string curr_string, int n) {
        
        if (curr_string.size() == n and curr_balance == 0) {
            record.push_back(curr_string);
        }
        
        
        if (curr_string.size() < n) {
            if (curr_balance > 0) {
                backtrack(record, curr_balance - 1, curr_string + ')', n);
            }

            backtrack(record, curr_balance + 1, curr_string + '(', n);
        }
    }
};
