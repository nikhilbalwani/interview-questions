class Solution {
public:
    int myAtoi(string str) {
        long long val = 0;
        bool negative = false;
        
        string::iterator itr = str.begin();
        
        while (*itr == ' ') {
            itr += 1;
        }
        
        if (*itr == '-' or *itr == '+') {
            if (*itr == '-') {
                negative = true;
            }
            itr += 1;
        }
        
        
        
        if ( ('0' > *itr) or ('9' < *itr) ) {
            return 0;
        }
        
        else {
            while ( (*itr >= '0') and (*itr <= '9') ) {
                val = 10 * val + (int) (*itr - '0');
                
                if ( ( negative and ( val > pow(2, 31) ) ) or ( (not negative) and (val > (pow(2, 31) - 1) ) ) ) {
                    if (negative) {
                        return (int) -pow(2, 31);
                    }
                    
                    else {
                        return (int) (pow(2, 31) - 1);
                    }
                }
                itr += 1;
            }
        }
        
        if (negative) {
            return -val;
        }
        return val;
    }
};
