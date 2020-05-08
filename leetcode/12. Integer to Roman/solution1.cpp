class Solution {
public:
    string intToRoman(int num) {
        int thousands = num / 1000;
        int hundreds = (num - thousands * 1000) / 100;
        int tens = (num - hundreds * 100 - thousands * 1000) / 10;
        int ones = num % 10;
        
        string ret = "";
        
        for (int i = 0; i < thousands; ++i) {
            ret += 'M';
        }
        
        if (hundreds < 4) {
            for (int i = 0; i < hundreds; ++i) {
                ret += 'C';
            }
        }
        
        if (hundreds == 4) {
            ret += "CD";
        }
        
        if (hundreds >= 5 and hundreds < 9) {
            ret += "D";
            
            for (int i = 6; i <= hundreds; ++i) {
                ret += 'C';
            }
        }
        
        if (hundreds == 9) {
            ret += "CM";
        }
        
        if (tens < 4) {
            for (int i = 0; i < tens; ++i) {
                ret += 'X';
            }
        }
        
        if (tens == 4) {
            ret += "XL";
        }
        
        if (tens >= 5 and tens < 9) {
            ret += "L";
            
            for (int i = 6; i <= tens; ++i) {
                ret += 'X';
            }
        }
        
        if (tens == 9) {
            ret += "XC";
        }
        
        if (ones < 4) {
            for (int i = 0; i < ones; ++i) {
                ret += 'I';
            }
        }
        
        if (ones == 4) {
            ret += "IV";
        }
        
        if (ones >= 5 and ones < 9) {
            ret += "V";
            
            for (int i = 6; i <= ones; ++i) {
                ret += 'I';
            }
        }
        
        if (ones == 9) {
            ret += "IX";
        }
        
        return ret;
    }
};
