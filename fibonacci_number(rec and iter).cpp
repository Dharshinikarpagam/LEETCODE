RECURSION:

class Solution {
public:
    int func(int n)
    {
        if(n<=1)
        {
            return n;
        }
        int last=func(n-1);
        int slast=func(n-2);
        return last+slast;
    }
    int fib(int n) {
        int res=func(n);
        return res;
    }
};

ITERATIVE:
class Solution {
public:
    int fib(int n) {
        if(n<=1)
        {
            return n;
        }
        int first=0;
        int sec=1;
        for(int i=2 ;i<=n;i++)
        {
            int third=first+sec;
            first=sec;
            sec=third;
        }
        return sec;
    }
};
