class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> cardsMap;
        int diff = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            if (cardsMap.find(cards[i]) == cardsMap.end()) {
                cardsMap.insert({cards[i], i});
            } else {
                diff = min(diff, i - cardsMap[cards[i]] + 1);
                cardsMap[cards[i]] = i;            
            }
        }
        return diff == INT_MAX ? -1 : diff;
    }
};