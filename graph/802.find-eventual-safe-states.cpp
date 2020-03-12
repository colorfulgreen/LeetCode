#include <vector>
using namespace std;

class Solution {
private:
    // return true if src can be topologically sorted
    // NOTE: graph 使用地址参数，以避免拷贝 vector 的时间开销
    bool dfs(vector< vector<int> >& graph, vector<int>& dp, int src) {
        if(dp[src] != 0)  // revisited, may be circle
            return dp[src] == 1;

        dp[src] = -1;
        for(int i=0; i<graph[src].size(); i++) {
            if(dfs(graph, dp, graph[src][i]) == false)
                return false;
        }
        return dp[src] = 1;
    }
public:
    vector<int> eventualSafeNodes(vector< vector<int> >& graph) {
        int N = graph.size();
        vector<int> dp(N, 0);
        vector<int> safeNodes;
        for(int i=0; i<N; i++) {
            if(dfs(graph, dp, i))
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
