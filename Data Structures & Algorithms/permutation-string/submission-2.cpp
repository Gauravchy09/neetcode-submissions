class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1;
        for(char ch: s1) mp1[ch]++;

        int l = 0, r = 0;
        unordered_map<char,int> mp2;
        while(r < s2.size()) {
            mp2[s2[r]]++;
            while((r-l+1) > s1.size()) {
                mp2[s2[l]]--;
                if(mp2[s2[l]] == 0) mp2.erase(s2[l]);
                l++;
            }

            if(mp2 == mp1) return true;
            r++;
        }
        if(mp1 == mp2) return true;
        return false;
    }
};
