class Solution {
  public:
    void func(int i,int n)
    {
        if(i<1)
        {
            return;
        }
        cout<<i<<" ";
        func(i-1,n);
    }
    void printNos(int n) {
    func(n,n);
        
    }
};
