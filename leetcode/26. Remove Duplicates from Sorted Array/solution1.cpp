class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int curr_num = nums[0];
        
        for (vector <int>::iterator itr = nums.begin() + 1;
             itr != nums.end(); ) {
            if (*itr != curr_num) {
                curr_num = *itr;
                itr += 1;
            }
            else {
                nums.erase(itr);
            }
        }
        
        return nums.size();
    }
};
