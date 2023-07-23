class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> profitHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> capitalHeap;

        for (int i = 0; i < capital.size(); i++) {
            capitalHeap.push({capital[i], profits[i]});
        }

        while (k--) {
            while (!capitalHeap.empty() &&  w >= capitalHeap.top().first) {
                pair<int, int> capitalHeapTop = capitalHeap.top();
                capitalHeap.pop();
                profitHeap.push({capitalHeapTop.second, capitalHeapTop.first});
            }
            if (!profitHeap.empty()) {
                pair<int, int> profitTop = profitHeap.top();
                profitHeap.pop();
                w += profitTop.first;
            }
        }

        return w;
    }
};