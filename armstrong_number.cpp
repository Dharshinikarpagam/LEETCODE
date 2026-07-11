class Solution {
  public:
    bool armstrongNumber(int n) {
        int dup=n;
        int rev=0;
        int sum=0;
        int cnt=0;
        int temp=n;
        while(temp>0)
        {
            cnt++;
            temp=temp/10;
        }
        while(n>0)
        {
            int ld=n%10;
            sum=sum+(ld*ld*ld); // or we can do pow(ld,cnt)
            rev=(rev*10)+ld;
            n=n/10;
        }
        if(sum==dup)
        {
            return true;
        }
        return false;
        
    }
};
