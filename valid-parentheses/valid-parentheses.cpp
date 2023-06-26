class Solution {
public:
    // can use vector as a stack, as it provides push back and pop_back methods
    // basic idea is every opening bracket must be closed by a corresponding closing bracket
    // so if it is a opening bracket then push_back
    // else check if the last pushed bracket matches the new bracket
    // if not return false
    bool isValid(string s) {
        vector<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push_back(s[i]);
            } else {
                if (st.size() == 0) { // important conditions to handle some edge cases
                    return false; // where if only cloising brackets are inserted (stack will be empty), then automatically false
                }
                char topElement = st[st.size() - 1];
                st.pop_back();
                if ((topElement == '(' && s[i] != ')') || (topElement == '[' && s[i] != ']') || (topElement == '{' && s[i] != '}')) {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};