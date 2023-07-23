class Solution {
public:
    bool topologicalSort(unordered_map<int, int> inDegree, map<int, vector<int>> edgeMap) {
        
        queue<int> myQ;
        for (auto it: inDegree) {
            if (it.second == 0) myQ.push(it.first);
        }

        while (!myQ.empty()) {
            int qSize = myQ.size(); 
            while (qSize -- ) {
                int index = myQ.front();
                // cout << "index " << index << endl;
                myQ.pop();
                for (int i = 0; i < edgeMap[index].size(); i++) {
                    int childIndex = edgeMap[index][i];
                    // cout << "child index " << index << endl;
                    if (inDegree.find(childIndex) != inDegree.end()) {
                        if (inDegree[childIndex] > 0) inDegree[childIndex]--;
                        // cout << "s1" << endl;
                        if (inDegree[childIndex] == 0) {
                            myQ.push(childIndex);
                            inDegree.erase(childIndex);
                        }
                    }
                }
                inDegree.erase(index);
            }
        }
        if (inDegree.size() == 0) return true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> edgeMap;
        unordered_map<int, int> inDegree;
        for (int i = 0; i < prerequisites.size(); i++) {
            int startIndex = prerequisites[i][0];
            int endIndex = prerequisites[i][1];
            if (edgeMap.find(endIndex) == edgeMap.end()) {
                edgeMap.insert({endIndex, {startIndex}});
            } else {
                edgeMap[endIndex].push_back(startIndex);
            }

            if (inDegree.find(startIndex) == inDegree.end()) {
                inDegree.insert({startIndex, 1});
            } else {
                inDegree[startIndex] ++;
            }

            if (inDegree.find(endIndex) == inDegree.end()) {
                inDegree.insert({endIndex, 0});
            }
        }
        // for (auto it: inDegree) {
        //     cout << it.first << " " << it.second << endl;
        // }

        return topologicalSort(inDegree, edgeMap);
    }
};