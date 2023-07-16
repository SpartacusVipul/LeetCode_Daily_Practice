class Solution {
public:
    // basic idea is calculate the slope between a point and every other point 
    // fix a starting point 
    // create a hashmap for this starting point 
    // then calcualte all slopes possible with this starting point 
    // note the case where poitns are in same vertical line (INF slope)
    // the loop runs from 0 to n and i + 1 to n, 
    // this is because any point i, need not check again with i - 1, because
    // it was already checked earlier
    // hash map is used for every point, and checked against every next points 
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for (int i = 0; i < points.size(); i++) {
            int px = points[i][0], py = points[i][1];
            unordered_map<float, int> uMap;
            for (int j = i + 1; j < points.size(); j++) {
                int nx = points[j][0], ny = points[j][1];
                float slope = INT_MAX;
                if (nx != px) 
                    slope = (float)(py - ny) / (float)(px - nx);
                if (uMap.find(slope) == uMap.end()) 
                    uMap.insert({slope, 1});
                else 
                    uMap[slope] ++;
                
                // cout << "start " << px << " " << py << " end " << nx << " " << ny << " ";
                // cout << slope << " " << uMap[slope] << endl; 
                res = max(res, uMap[slope] + 1);
            } 
        }
        return res;
    }
};