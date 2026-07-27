class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size()-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = nums.size()-1;
            int x = nums[i];
            while(j < k) {
                int y = nums[j], z = nums[k];
                if(x+y+z == 0) {
                    ans.push_back({x,y,z});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])j++;
                    while(j < k && nums[k] == nums[k+1])k--;
                }
                else if(x+y+z > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }

        return ans;
    }
};
