class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num ==1)
        {
            return true;
        }
        if(num < 1){
            return false;
        }
        double x = log(num) / log(4);
        if((int)x == x) {
            return true;
        }
        return false;
        // int c = 0;
        // while(num%2 == 0) {
        //     c++;
        //     num /= 2;
        // }
        // return c && !(c%2);
    }
};
