class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // Sorting the vector
        sort(nums.begin(), nums.end());
        
        int min_diff = INT_MAX;
        int best_sum;
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
            
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == target) {
                    return sum;
                }

                if ( abs(sum - target) < min_diff ) {
                    min_diff = abs(sum - target);
                    best_sum = sum;
                }

                if (sum < target) {
                    l += 1;
                }

                else {
                    r -= 1;
                }
            }
        }
        
        return best_sum;
        
    }
};
