class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> dist;

        int i = 0;
        for(auto &p: points) {
            int x = p[0], y = p[1];
            dist.push({x*x + y*y, i++});
            while(dist.size() > k) dist.pop();
        }

        while(dist.size()) {
            int p = dist.top().second;
            ans.push_back({points[p][0], points[p][1]});
            dist.pop();
        }

        return ans;
    }
};
