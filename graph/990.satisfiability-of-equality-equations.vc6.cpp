#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define C1 1
#define C2 -1

class Solution {
private:
    int hash(char c, map<char, int>& hashTable, vector< vector< pair<int, int> > >& G) {
        if(hashTable.find(c) == hashTable.end()) {
            hashTable[c] = hashTable.size();
            G.resize(hashTable.size());
        }
        return hashTable[c];
    }

    vector< vector< pair<int, int> > >  initTable(vector<string>& equations, vector< vector< pair<int, int> > >& G, map<char, int>& hashTable) {
        int i;
        int id1, id2;
        for(i=0; i<equations.size(); i++) {
            id1 = hash(equations[i][0], hashTable, G); 
            id2 = hash(equations[i][3], hashTable, G);
            G[id1].push_back(make_pair(id2, equations[i][1] == '='));
            G[id2].push_back(make_pair(id1, equations[i][1] == '='));
        }
        return G;
    }

    bool dfs(vector< vector< pair<int, int> > >& G, vector<int>& colors, int cur, int curColor) {
        if(colors[cur])
            return colors[cur] == curColor;

        pair<int, int> p;
        int i;

        colors[cur] = curColor;
        for(i=0; i<G[cur].size(); i++)
            if(G[cur][i].second && !dfs(G, colors, G[cur][i].first, curColor))
                return false;
        for(i=0; i<G[cur].size(); i++)
            if(!G[cur][i].second && colors[G[cur][i].first] == curColor)
                return false;
        
        return true;
    }

public:
    bool equationsPossible(vector<string>& equations) {
        map<char, int> hashTable;
        vector< vector< pair<int, int> > > G;
        vector<int> colors;
        int i, curColor;

        initTable(equations, G, hashTable);

        colors.assign(G.size(), 0);
        for(i=0, curColor=1; i<G.size(); i++) {
            if(colors[i])
                continue;
            if(!dfs(G, colors, i, curColor))
                return false;
             curColor++;
        }

        return true;
    }
};


int main(void) {
    vector<string> equations;
    bool r;
    equations.push_back("a==b");
    equations.push_back("b!=a");
    r = Solution().equationsPossible(equations);
    cout << r << endl;
    return 0;
}
