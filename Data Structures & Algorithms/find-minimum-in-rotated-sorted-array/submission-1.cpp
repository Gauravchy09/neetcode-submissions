class Solution {
public:
    int findMin(vector<int> &nums) {
        // brute-force:: O(N)
        // int mini = INT_MAX;
        // for(int x: nums) {
        //     mini = min(mini, x);
        // }
        // return mini; 

        // Optimal: O(log N)

        int low = 0, high = nums.size()-1;
        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
            
        }

        return nums[low];
    }
};
