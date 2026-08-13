class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCourses = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++;
            for(int neighbor: adj[curr]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completedCourses == numCourses;
    }
};
