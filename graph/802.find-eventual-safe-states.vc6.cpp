#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    void dfs(vector< vector<int> >& graph, set<int>& visited, set<int>& loop, set<int> path, int cur) {
        // find nodes which doesn't lead to circle , not only in circle
        // case: [[0],[2,3,4],[3,4],[0,4],[]]
        if(path.find(cur) != path.end() || loop.find(cur) != loop.end()) {
            for(set<int>::iterator i=path.begin(); i!=path.end(); i++)
                loop.insert(*i);
            return;
        }

        if(visited.find(cur) != visited.end())
            return;
        path.insert(cur);
        visited.insert(cur);
        
        for(int i=0; i<graph[cur].size(); i++)
            dfs(graph, visited, loop, path, graph[cur][i]);

    }
public:
    vector<int> eventualSafeNodes(vector< vector<int> >& graph) {
        set<int> visited;
        set<int> loop;
        set<int> path;
        int i;
        for(i=0; i<graph.size(); i++) {
            if(visited.find(i) == visited.end())
                dfs(graph, visited, loop, path, i);
        }

        vector<int> safeNodes;
        for(i=0; i<graph.size(); i++)
            if(loop.find(i) == loop.end())
                safeNodes.push_back(i);
        return safeNodes;
        
    }
};
