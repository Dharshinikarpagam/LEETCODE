class Solution {
  public:
    int floorSqrt(int n) {
       if(n<2) return n;
       int l=1;
       int h=n/2;
       int ans=0;
       while(l<=h)
       {
           int mid=l+(h-l)/2;
           if(mid*mid<=n)
           {
               ans=mid;
               l=mid+1;
           }
           else{
               h=mid-1;
           }
       }
       return ans;
        
    }
};
