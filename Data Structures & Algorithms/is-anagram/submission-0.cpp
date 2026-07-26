class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};
