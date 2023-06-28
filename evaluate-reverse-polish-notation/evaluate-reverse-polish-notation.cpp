class Solution {
public:

    // pretty straightforward
    int evalRPN(vector<string>& tokens) {
        vector<string> tokenStack;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" 
                || tokens[i] == "/") {
                int n1 = stoi(tokenStack.back());
                tokenStack.pop_back();
                int n2 = stoi(tokenStack.back());
                tokenStack.pop_back();
                int res = 0;
                if (tokens[i] == "+") {
                    res = n1 + n2;
                } else if (tokens[i] == "-") {
                    res = n2 - n1;
                } else if (tokens[i] == "*") {
                    res = n1 * n2;
                } else if (tokens[i] == "/") {
                    res = n2 / n1;
                }
                // cout << res << endl;
                tokenStack.push_back(to_string(res));
            }  else {
                // cout << tokens[i] << endl;
                tokenStack.push_back(tokens[i]);
            }
        }    
        return stoi(tokenStack.back());
    }
};