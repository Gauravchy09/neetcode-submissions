class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int x: nums) {
            mp[x]++;
        }

        vector<vector<int>>freq(n+1);
        for(auto &it: mp) {
            freq[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = n; i >= 1; i--) {
            if(ans.size()==k)break;
            for(int x: freq[i]) {
                ans.push_back(x);
                if(ans.size()==k)break;
            }
        }
        return ans;
    }
};
