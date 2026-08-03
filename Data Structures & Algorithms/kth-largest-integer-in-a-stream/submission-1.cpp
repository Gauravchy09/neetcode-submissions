class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = -1;
    KthLargest(int k, vector<int>& nums) {
        this->size = k;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            while(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();
        return pq.top();
    }
};
