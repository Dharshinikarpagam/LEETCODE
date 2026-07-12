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

BACKTRACKING :
class Solution {
  public:
    void func(int i,int n)
    {
        if(i>n)
        {
            return;
        }
        func(i+1,n);
        cout<<i<<" ";
    }
    void printNos(int n) {
      func(1,n);
        
    }
};
