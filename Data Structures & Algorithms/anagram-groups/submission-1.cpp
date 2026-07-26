class Solution {
public:
    bool isAnagram(string a, string b) {
        if(a.length() != b.length()) return false;
        vector<int>freq(26,0);
        for(char ch: a) {
            freq[ch-'a']++;
        }
        for(char ch: b) {
            freq[ch-'a']--;
        }
        for(int x:freq) {
            if(x != 0)return false;
        }

        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<int> visited(strs.size(),0);
        for(int i = 0; i < strs.size(); i++) {
            if(visited[i]) {
                continue;
            }
            vector<string> temp;
            temp.push_back(strs[i]);
            visited[i] = 1;
            for(int j = i+1; j < strs.size(); j++) {
                if(isAnagram(strs[i],strs[j])) {
                    temp.push_back(strs[j]);
                    visited[j] = 1;
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
};
