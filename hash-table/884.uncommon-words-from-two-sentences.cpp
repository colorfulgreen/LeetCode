#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> table;
        stringstream sa(A), sb(B);
        string word;
        vector<string> uncommon;
        while(sa >> word)
            table[word] += 1;
        while(sb >> word)
            table[word] += 1;
        for(const auto &w : table) {
            if(w.second == 1)
                uncommon.push_back(w.first);
        }
        return uncommon;
    }
};

int main(void) {
    Solution solution;
    vector<string> uncommon;
    uncommon = solution.uncommonFromSentences("this apple is sweet", "this apple is sour");
    for(string word: uncommon)
        cout << word << endl;
    return 0;
}
