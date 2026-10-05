class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(0);
            }
            else {
                int a = st.top();
                st.pop();

                if (a == 0) {
                    a = 1;
                }
                else {
                    a = 2 * a;
                }

                if (!st.empty()) {
                    int b = st.top();
                    st.pop();
                    st.push(b + a);
                }
                else {
                    st.push(a);
                }
            }
        }

        return st.top();
    }
};