class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minh;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int num :nums)
        {
            minh.push(num);
            if(minh.size()>k)
            {
                minh.pop();
            }
        }
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size()>size)
        {
            minh.pop();
        }
        return minh.top();
    }
};
 */
