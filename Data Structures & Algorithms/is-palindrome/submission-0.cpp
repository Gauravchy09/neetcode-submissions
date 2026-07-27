class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int i = 0, j = s.length()-1;
        while(i < j) {
            while(i < j && !isalnum(s[i]))i++;
            while(i < j && !isalnum(s[j]))j--;

            if(s[i] != s[j]) return false;

            i++;
            j--;
        }
        return true;
    }
};
