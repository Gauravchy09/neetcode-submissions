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
            unordered_map<char,int> freqs;
            for(int j = i; j < s.size(); j++) {
                freqs[s[j]]++;
                bool isvalid = true;
                for(auto &p: freqt) {
                    if(freqs.find(p.first) == freqs.end()) {
                        isvalid = false;
                        break;
                    }
                    else {
                        if(freqs[p.first] < p.second) {
                            isvalid = false;
                            break;
                        }
                    }
                }
                if(isvalid) {
                    minlen = min(minlen,j-i+1);
                    if(minlen == j-i+1) {
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return (minlen == INT_MAX) ? "" : ans;
    }
};
