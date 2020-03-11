#include <set>
#include <vector>
using namespace std;

class Solution {
private:
    void bfs(vector< vector<int> >& rooms, set<int>& visited, int room) {
        if(visited.find(room) != visited.end())
            return;

        visited.insert(room);
        for(int i=0; i<rooms[room].size(); i++)
            bfs(rooms, visited, rooms[room][i]);
    }

public:
    bool canVisitAllRooms(vector< vector<int> >& rooms) {
        set<int> visited;
        bfs(rooms, visited, 0);
        return visited.size() == rooms.size();
    }
};
