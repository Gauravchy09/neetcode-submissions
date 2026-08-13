class Solution {
public:
    int island_area(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j}); // starting point
        grid[i][j] = 0;
        vector<pair<int,int>> neighbors = {
            {0,1}, {1,0}, {-1,0}, {0,-1}
        };
        int area = 0;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            area++;

            for(auto &p: neighbors) {
                int dx = x + p.first;
                int dy = y + p.second;
                if(dx >= 0 && dy >= 0 && dx < grid.size() && dy < grid[0].size() && grid[dx][dy]) {
                    grid[dx][dy] = 0;
                    q.push({dx,dy});
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    maxarea = max(maxarea, island_area(grid,i,j));
                }
            }
        }
        return maxarea;
    }
};
