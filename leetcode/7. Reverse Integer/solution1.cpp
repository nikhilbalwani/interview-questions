class Solution {
public:
    int reverse(int x) {
        
        long long ret = 0, x1;
        bool minus = false;
        
        if (x / 10 == 0) {
            return x;
        }
        
        if (x < 0) {
            minus = true;
            x1 = -(long long) x;
        }
        else {
            x1 = x;
        }
        
        while (x1) {
            ret = x1 % 10 + 10 * ret;
            
            if ( (not minus and (ret > (pow(2, 31) ) - 1) ) or (minus and (ret > (pow(2, 31) ) ) ) ) {
                return 0;
            }
            
            x1 /= 10;
        }
        if (minus) {
            return -ret;
        }
        
        return ret;
        
    }
};
