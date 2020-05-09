class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        const int nums_length = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector <vector <int>> ret;
        
        if (nums.size() < 3) {
            return ret;
        }
        
        int prev_i = INT_MIN;
        
        for (int i = 0; i < nums_length; ++i) {
            
            if (prev_i == nums[i]) {
                continue;
            }
            
            int l = i + 1, r = nums_length - 1;
            int ele = nums[i];
            int prev_l = INT_MIN;
            int prev_r = INT_MIN;
            
            while (l < r) {
                
                if (nums[i] + nums[l] + nums[r] == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});

                    prev_l = nums[l];
                    prev_r = nums[r];

                    
                    while (nums[l] == prev_l and nums[r] == prev_r and l < r) {
                        r--;
                        l++;
                    }
                }
                
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
            
            prev_i = nums[i];
        }
        
        return ret;
        
    }
};
