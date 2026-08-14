class Solution {
public:
    bool ispossible(vector<int>& piles, int k, int h) {
        int totalhrs = 0;
        for(int p: piles) {
            if(p <= k) totalhrs += 1;
            else totalhrs += (p + k - 1) / k;

            if(totalhrs > h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for(int x: piles) high = max(high, x);

        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(ispossible(piles,mid,h)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
