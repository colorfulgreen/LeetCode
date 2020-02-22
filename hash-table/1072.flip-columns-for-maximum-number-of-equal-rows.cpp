#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int maxRows = 0;
        map<vector<int>, int> count;
        vector<int> reverseRow;
        for(auto row: matrix) {
            reverseRow = {};
            for(auto value: row)
                reverseRow.push_back(1 - value);
            count[row]++;
            count[reverseRow]++;
        }

        for(auto pair: count) {
            if(pair.second > maxRows)
                maxRows = pair.second;
        }
        return maxRows;
    }
};

int main(void) {
    Solution solution;
    int maxRows;
    vector<vector<int>> matrix {{0,0,0}, {0,0,1}, {1,1,0}};
    maxRows = solution.maxEqualRowsAfterFlips(matrix);
    cout << maxRows << endl;
    return 0;
}
