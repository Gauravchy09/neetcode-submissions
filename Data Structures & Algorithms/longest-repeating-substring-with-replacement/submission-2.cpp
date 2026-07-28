class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l = 0, r = 0;
        int maxlen = 0, maxfreq = 0;
        while(r < s.length()) {
            mp[s[r]]++;
            maxfreq = max(maxfreq,mp[s[r]]);
            if((r-l+1)-maxfreq > k) {
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
