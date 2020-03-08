#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector< vector<int> > & prerequisites) {
		cout << "safsaf" << endl;

        vector<int> order;
		vector<int> failed;
        map<int, int> indegrees;
        queue<int> zeroIndegrees;
		int course, i;

        for(i=0; i<prerequisites.size(); i++) 
			indegrees[prerequisites[i][0]]++;
		for(i=0; i<numCourses; i++)
			if(indegrees[i] == 0)
				zeroIndegrees.push(i);

        while(!zeroIndegrees.empty()) {
			course = zeroIndegrees.front();
			zeroIndegrees.pop();
			order.push_back(course);
			for(i=0; i<prerequisites.size(); i++) {
				if(prerequisites[i][1] == course) 
					if(--indegrees[prerequisites[i][0]] == 0) 
						zeroIndegrees.push(prerequisites[i][0]);
			}
        }


		if(order.size() == numCourses)
			return order;

		return failed;
    }
};

int main() {
	int numCourses = 4;
	vector<int> order;
	vector< vector<int> > prerequisites(4);
	prerequisites[0].push_back(1);  prerequisites[0].push_back(0);
	prerequisites[1].push_back(2);  prerequisites[1].push_back(0);
	prerequisites[2].push_back(3);  prerequisites[2].push_back(1);
	prerequisites[3].push_back(3);  prerequisites[3].push_back(2);
	
	order = Solution().findOrder(numCourses, prerequisites);
	for(int i=0; i<order.size(); i++)
		cout << order[i] << endl;

	return 0;
}
