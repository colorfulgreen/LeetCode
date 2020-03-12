#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Entry {
    string id;
    double weight;
    Entry(string id_, double weight_): id(id_), weight(weight_) {}
};

class Solution {
private:
    map<string, vector<Entry *> > initTable(vector< vector<string> >& equations, vector<double>& values) {
        map<string, vector<Entry *> > T;
        vector<string> e;
        int i;
        for(i=0; i<equations.size(); i++) {
            e = equations[i];
            T[e[0]].push_back(new Entry(e[1], values[i]));
            T[e[1]].push_back(new Entry(e[0], 1/values[i]));
        }
        return T;
    }

    double dfs(map<string, vector<Entry *> > T, string from, string to, set<string>& visited) {
        if(visited.find(from) != visited.end())
            return -1.0;
        visited.insert(from);

        double answer = -1.0;
        int i;
        for(i=0; i<T[from].size(); i++) {
            if(T[from][i]->id == to)
                return T[from][i]->weight;;
            if((answer = dfs(T, T[from][i]->id, to, visited)) != -1.0)
                return T[from][i]->weight * answer;
        }
        return -1.0;
    }

public:
    vector<double> calcEquation(vector< vector<string> >& equations, vector<double>& values, vector< vector<string> >& queries) {
        map<string, vector<Entry *> > T = initTable(equations, values);
        vector<double> answers;
        set<string> visited;
        double answer;
        int i;
        for(i=0; i<queries.size(); i++) {
            visited.clear();
            if(T.find(queries[i][0]) == T.end() || T.find(queries[i][1]) == T.end()) {
                answers.push_back(-1.0);
                continue;
            }
            if(queries[i][0] == queries[i][1]) {
                answers.push_back(1.0);
                continue;
            }
            answer = dfs(T, queries[i][0], queries[i][1], visited);
            answers.push_back(answer);
        }
        return answers;
    }
};
