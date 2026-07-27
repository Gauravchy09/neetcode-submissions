class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int prod = 1;
        vector<int> pref(nums.size(),0);
        vector<int> suff(nums.size(),0);
        pref[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i-1]*nums[i];
        }
        suff[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2; i >= 0; i--) {
            suff[i] = suff[i+1]*nums[i];
        }

        ans[0] = suff[1];
        ans[nums.size()-1] = pref[nums.size()-2];
        for(int i = 1; i < nums.size()-1; i++) {
            ans[i] = (pref[i-1]*suff[i+1]);
        }
        return ans;
    }
};
