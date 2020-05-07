class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        if (x == 0) {
            return true;
        }
        
        int upper = (int) pow(10, int(log10(x)) );
        int lower = 1;
        int mid = (int) pow(10, int(log10(x)) / 2 );
        
        while (upper > mid) {
            
            
            int num1 = (x / upper) % 10;
            int num2 = (x / lower) % 10;
            
            if (num1 != num2) {
                return false;
            }
            
            upper /= 10;
            lower *= 10;
        }
        
        return true;
    }
};
