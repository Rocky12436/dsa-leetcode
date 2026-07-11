class Solution {
public:
    bool isValid(string s) {

        stack<char> ch;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                ch.push(s[i]);
            }
            else {

                if (ch.empty()) {
                    return false;
                }

                if (s[i] == ')' && ch.top() == '(') {
                    ch.pop();
                }
                else if (s[i] == ']' && ch.top() == '[') {
                    ch.pop();
                }
                else if (s[i] == '}' && ch.top() == '{') {
                    ch.pop();
                }
                else {
                    return false;
                }
            }
        }

        return ch.empty();
    }
};