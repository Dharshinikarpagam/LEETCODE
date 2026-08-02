class maxHeap {
  private:
    priority_queue<int> maxheap;
  public:
    void push(int x) {
        maxheap.push(x);
        
    }
    void pop() {
        if(!maxheap.empty())
        {
            maxheap.pop();
        }
    }
    int peek() {
        if(maxheap.empty()) return -1;
        return maxheap.top();
        
    }
    int size() {
        return maxheap.size();
    }
    bool empty()
    {
        return maxheap.empty();
    }
};
