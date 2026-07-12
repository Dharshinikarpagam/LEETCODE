class Solution {
  public:
    void func(int i,int n)
    {
        if(i>n)
        {
            return;
        }
        cout<<i<<" ";
        func(i+1,n);
    }
    void printTillN(int n) {
       func(1,n);
        
    }
};

BACKTRACKING:

class Solution {
  public:
    void func(int i,int n)
    {
        if(i<1)
        {
            return;
        }
        func(i-1,n);
        cout<<i<<" ";
    }
    void printTillN(int n) {
       func(n,n);
        
    }
};
