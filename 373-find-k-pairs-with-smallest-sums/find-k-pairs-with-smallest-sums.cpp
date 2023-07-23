struct Compare {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};
// interesting idea, since the input is already sorted, 
// have a pq of min heap, and structure of heap elements is {sum, {i, j}} 
// that is sum and the indices to to obtain this sum 
// have a visited array that has {i, j} 
// every time, get top, insert the top to resVec, 
// since array is sorted and we are always increasing bith i and j
// the pq even if first array has all lower elements and second array has very large elements, 
// every time we insert first from both arrays, (since we are increasing i by 1 everytime)
// so, everytime we insert both arrays, and get only res from first array.. something like this  
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> resVec;
        set<pair<int, int>> visited;
        pq.push({nums1[0] + nums2[0], {0, 0}});

        while (k-- && !pq.empty()) {
            pair<int, pair<int, int>> pqTop = pq.top();
            pq.pop();
            int i = pqTop.second.first, j = pqTop.second.second;
            resVec.push_back({nums1[i], nums2[j]});
            if (i + 1 < n1 && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n2 && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }

        }

        return resVec;
    }
};