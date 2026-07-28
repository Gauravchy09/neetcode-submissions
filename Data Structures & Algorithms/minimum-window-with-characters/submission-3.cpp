class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need;

        for (char c : t)
            need[c]++;

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // If this character is still needed,
            // we've matched one more required character.
            if (need[s[right]] > 0)
                count++;

            // Include current character in the window.
            need[s[right]]--;

            // Window is valid
            while (count == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                need[s[left]]++;

                // If it becomes needed again,
                // window is no longer valid.
                if (need[s[left]] > 0)
                    count--;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
