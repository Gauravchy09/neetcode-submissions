class Solution {
public:
    int maxfreq(unordered_map<char,int>& mp) {
        int maxf = 1;
        for(auto &p: mp) {
            maxf = max(maxf,p.second);
        }
        return maxf;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l = 0, r = 0;
        int maxlen = 0;
        while(r < s.length()) {
            mp[s[r]]++;
            while((r-l+1)-maxfreq(mp) > k) {
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
