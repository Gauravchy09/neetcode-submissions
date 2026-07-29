class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(string &str: tokens) {
            if(str == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a+b);
            }
            else if(str == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b-a);
            }
            else if(str == "*") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b*a);
            }
            else if(str == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b/a);
            }
            else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
