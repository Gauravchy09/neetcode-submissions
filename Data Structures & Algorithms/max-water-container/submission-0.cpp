class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int maxarea = 0;
        while(i < j) {
            int area = (j-i)*min(nums[i],nums[j]);
            maxarea = max(maxarea,area);
            if(nums[i]<nums[j]) {
                i++;
            }
            else if(nums[j] < nums[i]) {
                j--;
            }
            else {
                if(nums[i+1] > nums[j-1]) i++;
                else j--;
            }
        }
        return maxarea;
    }
};
