class Solution {
public:
    vector<int> topologicalSort(vector<int> inDegree, map<int, vector<int>> edgeMap) {
        
        queue<int> myQ;
        vector<int> resVec;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) myQ.push(i);
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
                    if (inDegree[childIndex] > 0) {
                        inDegree[childIndex]--;
                        if (inDegree[childIndex] == 0) {
                            myQ.push(childIndex);
                        }
                    }
                }
                resVec.push_back(index);
            }
        }
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] > 0) {
                return {};
            }
        }
        return resVec;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> edgeMap;
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int startIndex = prerequisites[i][0];
            int endIndex = prerequisites[i][1];
            if (edgeMap.find(endIndex) == edgeMap.end()) {
                edgeMap.insert({endIndex, {startIndex}});
            } else {
                edgeMap[endIndex].push_back(startIndex);
            }

            inDegree[startIndex] ++;
        }
        // for (auto it: inDegree) {
        //     cout << it.first << " " << it.second << endl;
        // }
        vector<int> resVec;
        if (prerequisites.size() == 0) {
            for (int i = 0; i < numCourses; i++) {
                resVec.push_back(i);
            }
            return resVec;
        }
        return topologicalSort(inDegree, edgeMap);
    }
};