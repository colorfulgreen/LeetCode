#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(auto num: nums) {
            count[num]++;
        }

        vector<int> topK;
        priority_queue<pair<int, int>> pq;
        for(auto c=count.begin(); c!=count.end(); c++) {
            pq.push(make_pair(c->second, c->first));
            if(pq.size() > count.size() - k) {
                topK.push_back(pq.top().second);
                pq.pop();
            }
        }

        return topK;
    }
};

int main(void) {
    vector<int> nums = {1,1,1,2,2,3};
    Solution s;
    vector<int> topK;
    topK = s.topKFrequent(nums, 2);
    for(int k: topK)
        cout << k << " ";
    cout << endl;
    return 0;
}
