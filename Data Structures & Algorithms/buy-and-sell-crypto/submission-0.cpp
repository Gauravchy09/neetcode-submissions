class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        for(int x: prices) {
            mini = min(mini,x);
            profit = max(profit,x-mini);
        }
        return profit;
    }
};
