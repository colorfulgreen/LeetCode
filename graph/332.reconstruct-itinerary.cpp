#include <vector>
#include <string>
#include <multiset>
using namespace std;

class Solution {
private:
    void dfs(map<string, multiset<string> >& G, vector<string>& paths, string from) {
        string to;

        // By writing down the path backwards when retreating from recursion, 
        // merging the cycles into the main path is easy - 
        // the end part of the path has already been written, 
        // the start part of the path hasn't been written yet, 
        // so just write down the cycle now and then keep backwards-writing the path.
        while(G[from].size()) {
            to = G[from].begin();  G[from].erase(to);
            paths.push_back(to);
            dfs(G, paths, to);
        }
        paths.push_back(from);
    }

public:
    vector<string> findItinerary(vector< vector<string> >& tickets) {
        map<string, multiset<string> > G;
        vector<string> paths;
        int i;

        // init graph
        for(i=0; i<tickets.size(); i++) 
            G[tickets[i][0]].insert(tickets[i][1]);

        dfs(G, paths, "JFK");
        return vector<string>(paths.rbegin(), paths.rend());
    }
};
