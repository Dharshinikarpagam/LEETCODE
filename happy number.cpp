class Solution {
public:
    int square(int n)
    {
        int sum=0;
        while(n>0)
        {
            int rem=n%10;
            sum+=rem*rem;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1)
        {
            if(st.find(n)!=st.end())
            {
                return false;
            }
            st.insert(n);
            n=square(n);
        }
        return true;
    }
};
