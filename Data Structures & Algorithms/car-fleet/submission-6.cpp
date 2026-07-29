class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<float> st;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[position[i]] = i;
        }
        sort(position.rbegin(),position.rend());

        for(int i = 0; i < n; i++) {
            float time = (target-position[i])/(1.0*speed[mp[position[i]]]);
            if(st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};
