class Solution {
public:
    int findMin(vector<int> &nums) {
        // brute-force:: O(N)
        int mini = INT_MAX;
        for(int x: nums) {
            mini = min(mini, x);
        }
        return mini; 
    }
};
