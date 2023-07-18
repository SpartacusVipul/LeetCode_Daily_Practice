class Solution {
public:
    // basic idea is to maintain a neighbour map to reduce the search area
    // in every iteration from all elements in the wordList to limited neighbours
    // this works only because all words are of same size, so 
    // for a a given word, generate all patterns and insert the word using the pattern as key 
    // into the neighbour map
    // now when we pop an element from the queue, we only search within the possible patterns 
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> myQ;
        myQ.push({beginWord, 1});
        unordered_set<string> visited ;
        visited.insert(beginWord);
        // create a neighbourMap of patterns
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> neighbourMap;
        for (int i = 0; i < wordList.size(); i++) {
            string baseWord = wordList[i];
            for (int i = 0; i < baseWord.size(); i++) {
                string pattern = baseWord;
                pattern[i] = '*';
                if (neighbourMap.find(pattern) == neighbourMap.end()) {
                    neighbourMap.insert({pattern, {baseWord}});
                } else {
                    neighbourMap[pattern].push_back(baseWord);
                }
            }
        }

        while (!myQ.empty()) {
            pair<string, int> pos = myQ.front();
            myQ.pop();
            for (int i = 0; i < pos.first.size(); i++) {
                string pattern = pos.first;
                pattern[i] = '*';
                for (int i = 0; i < neighbourMap[pattern].size(); i++) {
                    if (visited.find(neighbourMap[pattern][i]) == visited.end()) {
                        if (neighbourMap[pattern][i] == endWord) return pos.second + 1;
                        visited.insert(neighbourMap[pattern][i]);
                        myQ.push({neighbourMap[pattern][i], pos.second + 1});
                        
                    }
                }
            }
            
        }
        return 0;
    }
};