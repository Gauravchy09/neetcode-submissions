class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            if(j-i+1 > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(j-i+1 == k) {
                int maxi = INT_MIN;
                for(auto &p: mp) {
                    maxi = max(maxi,p.first);
                }
                ans.push_back(maxi);
            }
        }
        return ans;
    }
};
