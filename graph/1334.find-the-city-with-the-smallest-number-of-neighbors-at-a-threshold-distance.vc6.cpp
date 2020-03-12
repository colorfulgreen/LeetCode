class Solution {
private:
    vector< vector< pair<int, int> > > initGraph(int n, vector< vector<int> >& edges) {
        int i;
        vector< vector< pair<int, int> > > G;

        G.resize(n);
        for(i=0; i<edges.size(); i++) {
            G[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            G[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
        }
        return G;
    }

    void dfs(vector< vector< pair<int, int> > >& G, map<int, int>& visited, int city, int distanceThreshold, int distance) {
        int i;

        if(distance > distanceThreshold)
            return;
        if(visited.find(city) != visited.end() && visited[city] <= distance)
            return;

        visited[city] = distance;
        for(i=0; i<G[city].size(); i++)
            dfs(G, visited, G[city][i].first, distanceThreshold, G[city][i].second + distance);
    }

public:
    int findTheCity(int n, vector< vector<int> >& edges, int distanceThreshold) {
        int city, minNum = n, i;
        vector< vector< pair<int, int> > > G = initGraph(n, edges);
        map<int, int> visited;

        for(i=0; i<n; i++) {
            visited.clear();
            dfs(G, visited, i, distanceThreshold, 0);
            if(visited.size() <= minNum) {
                city = i;
                minNum = visited.size();
            }
        }

        return city;
    }
};
