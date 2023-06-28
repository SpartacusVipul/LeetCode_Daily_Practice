class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        vector<string> vs;
        string dir = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (dir == "..") {
                    if (vs.size() > 0)
                        vs.pop_back();
                } else if (dir != "." && dir != "") {
                    vs.push_back(dir);
                }
                dir = "";
            } else {
                dir += path[i];
            }
        }
        string res = "";
        if (vs.size() > 0) {
            for (int i = 0; i < vs.size(); i++) {
                res += "/" + vs[i];
            }
        } else {
            res = "/";
        }
        
        return res;
    }
};