class Solution {
public:
    //ayyappasamy sakshiga, asalu error vasthe, naku telidu
    // i solemnly swear that I am not responsible for any of the errors.
    double currentVal = 1.0;
    double dfs(map<string, vector<pair<string,double>>> edgeMap, string startIndex, string targetIndex, double value, unordered_map<string, int> &visited) {
        visited[startIndex] = 1;
        if (edgeMap.find(startIndex) == edgeMap.end() || edgeMap.find(targetIndex) == edgeMap.end()) {
            return -1.0;
        }
        if (startIndex == targetIndex) {
            return value;
        }

        for (int i = 0; i < edgeMap[startIndex].size(); i++) {
            if (!visited[edgeMap[startIndex][i].first]) {
                double res = dfs(edgeMap, edgeMap[startIndex][i].first, targetIndex, value * edgeMap[startIndex][i].second, visited);
                if (res != -1) {
                    return res;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector< pair<string, double> >> edgeMap;
        // this took, way longer than it should
        for (int i = 0; i < equations.size(); i++) {
            string startIndex = equations[i][0];
            string endIndex = equations[i][1];
            if (edgeMap.find(startIndex) == edgeMap.end()) {
                vector<pair<string, double>> temp;
                temp.push_back(pair<string, double>(endIndex, values[i]));
                edgeMap.insert(make_pair(startIndex, temp));

            } else {
                edgeMap[startIndex].push_back(pair<string, double>(endIndex, values[i]));
            }
            if (edgeMap.find(endIndex) == edgeMap.end()) {
                vector<pair<string, double>> temp;
                temp.push_back(pair<string, double>(startIndex, 1.0 / values[i]));
                cout << 1.0 / values[i] << endl;
                edgeMap.insert(make_pair(endIndex, temp));

            } else {
                edgeMap[endIndex].push_back(pair<string, double>(startIndex, 1.0 / values[i]));
            }   
        }    
        vector<double> resVec;
        for (int i = 0; i < queries.size(); i++) {
            unordered_map<string, int> visited;
            resVec.push_back(dfs(edgeMap, queries[i][0], queries[i][1], 1.0, visited));
        }

        return resVec;

    }
};