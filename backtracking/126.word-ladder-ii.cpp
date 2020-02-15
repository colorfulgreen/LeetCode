#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// TODO
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), current, next;
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        unordered_map<string, vector<string>> children;
        vector<vector<string>> ladders;
        vector<string> ladder;
        current.insert(beginWord);
        ladder.push_back(beginWord);
        while (true) {
            cout << "Current: ";
            for (string word : current) {
                cout << word << " ";
                dict.erase(word);
            }
            cout << endl;
            for (string word : current) {
                findChildren(word, next, dict, children);
            }
            if (next.empty()) {
                break;
            }
            if (next.find(endWord) != next.end()) {
                genLadders(beginWord, endWord, children, ladder, ladders);
                break;
            }
            current.clear();
            swap(current, next);
        }
        return ladders;
    }
private:

    void findChildren(string word, unordered_set<string>& next, unordered_set<string>& dict, unordered_map<string, vector<string>>& children) {
        string parent = word;
        for (int i = 0; i < word.size(); i++) {
            char t = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if (dict.find(word) != dict.end()) {
                    next.insert(word);
                    children[parent].push_back(word);
                }
            }
            word[i] = t;
        }
    }

    void genLadders(string beginWord, string endWord, unordered_map<string, vector<string>>& children, vector<string>& ladder, vector<vector<string>>& ladders) {
        if (beginWord == endWord) {
            ladders.push_back(ladder);
        } else {
            for (string child : children[beginWord]) {
                ladder.push_back(child);
                genLadders(child, endWord, children, ladder, ladders);
                ladder.pop_back();
            }
        }
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution solution;
    vector<vector<string>> ladders = solution.findLadders(beginWord, endWord, wordList);
	for (vector<string> ladder : ladders) {
        for(string word: ladder) {
            cout << word << " ";
        }
        cout << endl;
	}
    return 0;
}
