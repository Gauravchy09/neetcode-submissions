class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";

        unordered_map<char,int> freqt;
        for(char ch: t) freqt[ch]++;

        // brute-force:: O(N^2)::
        int minlen = INT_MAX;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            unordered_map<char,int> freqs = freqt;
            for(int j = i; j < s.size(); j++) {
                if(freqs.find(s[j]) != freqs.end()) {
                    freqs[s[j]]--;
                    if(freqs[s[j]] == 0) freqs.erase(s[j]);
                }
                if(freqs.empty()) {
                    minlen = min(minlen,j-i+1);
                    if(minlen == j-i+1) {
                        ans = s.substr(i,j-i+1);
                    }
                    break;
                }
            }
        }
        return (minlen == INT_MAX) ? "" : ans;
    }
};
