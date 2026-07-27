class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int x: nums) {
            st.insert(x);
        }   
        int maxlen = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]-1) == st.end()) {
                int len = 0;
                int num = nums[i];
                while(st.find(num) != st.end()) {
                    len++;
                    num++;
                }
                maxlen = max(maxlen,len);
            }
        }

        return maxlen;
    }
};
