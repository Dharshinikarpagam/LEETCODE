class Solution {
public:
    int countCommas(int n) {
        long long start=1000;
        long long comma=1;
        long long ans=0;
        while(start<=n)
        {
            long long end=start*1000-1;
            end=min(end,(long long)n);
            long long cnt=end-start+1;
            ans+=cnt*comma;
            start*=1000;
            comma++;
        }
        return ans;
        
    }
};
