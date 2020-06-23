class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        if (arr.size() < 2) {
            return -1;
        }
        
        vector <int> min_len(arr.size(), INT_MAX);
        
        int j = 0, i, curr_sum = 0, min_sum = INT_MAX;
        
        for (i = 0; i < arr.size(); ++i) {
            curr_sum += arr[i];
            
            while (j < i && curr_sum > target)  {
                curr_sum -= arr[j];
                j += 1;
            }
            
            if (curr_sum == target) {
                if (i > 0) {
                    min_len[i] = min(min_len[i - 1], i - j + 1);
                }
                else {
                    min_len[i] = i - j + 1;
                }
                
                if (j > 0) {
                    if (min_len[i] != INT_MAX 
                        && min_len[j - 1] != INT_MAX) {
                        min_sum = std::min(min_sum, min_len[j - 1] + i - j + 1);
                    }
                }
                
            }
            else if (i > 0) {
                min_len[i] = min_len[i - 1];
            }
        }
        
        if (min_sum == INT_MAX) {
            return -1;
        }
        
        return min_sum;
    }
}; 
