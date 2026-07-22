class Solution {
    priority_queue<int,vector<int>,greater<int>> minh;
    int size;
public:
    int findKthLargest(vector<int>& nums, int k) {
        size=k;
        for(int num:nums)
        {
            minh.push(num);
            if(minh.size()>k)
            {
                minh.pop();
            }
        }
        return minh.top();
        
    }
};
