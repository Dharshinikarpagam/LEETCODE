Definition:
A subsequence is obtained by keeping the order of characters the same, but you may skip characters.
Characters need not be adjacent.
Order must remain the same.

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        int minlen=INT_MAX;
        int st=-1;
        int l=0;
        while(l<n)
        {
            int r=0;
            while(l<n)
            {
                if(s1[l]==s2[r])
                {
                    r++;
                }
                if(r==m)
                {
                    break;
                }
                l++;
            }
            if(l==n)
            {
                break;
            }
            int end=l;
            r=m-1;
            while(r>=0)
            {
                if(s1[l]==s2[r])
                {
                    r--;
                }
                l--;
            }
            l++;
            if((end-l+1)<minlen)
            {
                minlen=end-l+1;
                st=l;
            }
            l++;
        }
        return st==-1? "":s1.substr(st,minlen);
        
    }
};
