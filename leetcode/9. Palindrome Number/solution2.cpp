class Solution {
public:
    bool isPalindrome(int x) {
        long long int curr_number = x, rev_number = 0;
        
        if (x < 0) {
            return false;
        }
        
        do {
            rev_number = 10 * rev_number + curr_number % 10;
            
            curr_number /= 10;
        } while (curr_number > 0);
        
        return (rev_number == x);
    }
};
