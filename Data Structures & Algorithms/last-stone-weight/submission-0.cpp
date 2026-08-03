class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() <= 1) return stones[0];

        priority_queue<int> pq;
        for(int x: stones) pq.push(x);

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x == y) continue;
            if(x < y) pq.push(y-x);
            else pq.push(x-y);
        }

        return (pq.size() > 0) ? pq.top() : 0;
    }
};
